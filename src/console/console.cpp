// This file is part of CE3D. License: GPL3

#include "console/console.h"

#include "util/keyboard_state.h"

namespace CE3D
{

Console*                   Console::s_Instance = nullptr;
std::shared_ptr<Functor<>> Console::s_Callback(nullptr);
boost::signals2::mutex     Console::s_KbThreadMutex;
boost::signals2::mutex     Console::s_CreationMutex;
boost::signals2::mutex     Console::s_DrawMutex;
bool                       Console::s_ThreadTerminator;

void Console::KeyboardThread()
{
    // ATTENTION: dont dare to lock another mutex here since they may lock out
    // each other!
    char c;

    halfdelay(1);

    KeyboardState *KbState = KeyboardState::GetInstance();
    s_KbThreadMutex.lock();
    while (!s_ThreadTerminator)
    {
        s_KbThreadMutex.unlock();
        c = getch();

        if (c != ERR)
        {
            KbState->SetState(c);

            if (s_Callback != nullptr)
            {
                try
                {
                    (*s_Callback)();
                }
                catch (...)
                {
                    // TODO debug output
                }
            }
        }
        s_KbThreadMutex.lock();
    }
    s_KbThreadMutex.unlock();
}

Console::Console()
{
    // initialize curses
    m_Screen = initscr();

    // pass all keys to the program, dont allow ^C interrupt
    raw();

    // allow reading more keys! :)
    keypad(stdscr, TRUE);

    // turn of auto echoing
    noecho();

    // get terminal height/width
    getmaxyx(m_Screen, m_Height, m_Width);

    s_ThreadTerminator = false;
    m_KeyboardThread = new boost::thread(Console::KeyboardThread);

    m_HasColors = has_colors();

    InitColorPairs();
}

Console::~Console()
{
    s_KbThreadMutex.lock();
    s_ThreadTerminator = true;
    s_KbThreadMutex.unlock();
    m_KeyboardThread->join();
    delete m_KeyboardThread;
    endwin();

}

Console* Console::GetInstance()
{
    s_CreationMutex.lock();
    if (s_Instance == nullptr)
    {
        s_Instance = new Console();
    }
    s_CreationMutex.unlock();
    return s_Instance;
}

void Console::DeleteInstance()
{
    s_CreationMutex.lock();
    s_DrawMutex.try_lock();
    if (s_Instance != nullptr)
    {
        delete s_Instance;
        s_Instance = nullptr;
    }
    s_DrawMutex.unlock();
    s_CreationMutex.unlock();
}

void Console::Flush() const
{
    s_DrawMutex.lock();
    refresh();
    s_DrawMutex.unlock();
}

void Console::Clear() const
{
    s_DrawMutex.lock();
    clear();
    s_DrawMutex.unlock();
}

void Console::InitColorPairs()
{
    s_DrawMutex.lock();
    for (std::uint8_t i = 0; i < ConsoleColor::LAST; ++i)
    {
        for (std::uint8_t j = 0; j< ConsoleColor::LAST; ++j)
        {
            init_pair(ConsoleStringAttributes::ColorPairIndex(
                          static_cast<ConsoleColor>(i),
                          static_cast<ConsoleColor>(j)),
                      i, j);
        }
    }
    s_DrawMutex.unlock();
}

void Console::WriteChar(ConsoleStringAttributes const attr,
                        char const character)
{
    s_DrawMutex.lock();
    attroff(m_CurrentAttributes.GetCursesRepresentation());
    attron(attr.GetCursesRepresentation());

    addch(character);

    attroff(attr.GetCursesRepresentation());
    attron(m_CurrentAttributes.GetCursesRepresentation());
    s_DrawMutex.unlock();
}

void Console::WriteChar(ConsoleIdxType const x, ConsoleIdxType const y,
               ConsoleStringAttributes const attr, char const character)
{
    s_DrawMutex.lock();
    attroff(m_CurrentAttributes.GetCursesRepresentation());
    attron(attr.GetCursesRepresentation());

    mvaddch(y, x, character);

    attroff(attr.GetCursesRepresentation());
    attron(m_CurrentAttributes.GetCursesRepresentation());
    s_DrawMutex.unlock();
}

void Console::WriteChar(ConsoleIdxType const x, ConsoleIdxType const y,
                        char const character)
{
    s_DrawMutex.lock();
    mvaddch(y, x, character);
    s_DrawMutex.unlock();
}

void Console::WriteChar(char const character)
{
    s_DrawMutex.lock();
    addch(character);
    s_DrawMutex.unlock();
}

void Console::SetPosition(ConsoleIdxType const x, ConsoleIdxType const y)
{
    s_DrawMutex.lock();
    move(y, x);
    s_DrawMutex.unlock();
}

void Console::SetAttributes(ConsoleStringAttributes const attr)
{
    s_DrawMutex.lock();
    m_CurrentAttributes = attr;
    s_DrawMutex.unlock();
}

}
