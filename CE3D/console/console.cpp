// This file is part of CE3D. License: GPL3

#include "CE3D/console/console.h"

#include "CE3D/util/keyboard_state.h"

namespace CE3D
{

std::function<void()>       Console::s_Callback(nullptr);
boost::signals2::mutex      Console::s_CreationMutex;
boost::signals2::mutex      Console::s_DrawMutex;
bool                        Console::s_ThreadTerminator;
bool                        Console::s_HasColors;
ConsoleIdxType              Console::s_Height;
ConsoleIdxType              Console::s_Width;
WINDOW                     *Console::s_Screen;
std::uint16_t               Console::s_InstanceCount;
boost::thread              *Console::s_KeyboardThread;


void Console::KeyboardThread()
{
    // ATTENTION: dont dare to lock another mutex here since they may lock out
    // each other!
    char c;

    halfdelay(1);

    KeyboardState *KbState = KeyboardState::GetInstance();
    // This is just a reading access so we can avoid using a mutex here
    while (!s_ThreadTerminator)
    {
        c = getch();

        if (c != ERR)
        {
            KbState->SetState(c);

            if (s_Callback)
            {
                try
                {
                    s_Callback();
                }
                catch (...)
                {
                    // TODO debug output
                }
            }
        }
    }
}

Console::Console()
{
    s_CreationMutex.lock();

    if (s_InstanceCount++ == 0)
    {
        // initialize curses
        s_Screen = initscr();

        // pass all keys to the program, dont allow ^C interrupt
        raw();

        // allow reading more keys! :)
        keypad(stdscr, TRUE);

        // turn of auto echoing
        noecho();

        s_ThreadTerminator = false;
        s_KeyboardThread = new boost::thread(Console::KeyboardThread);

        // get terminal height/width
        getmaxyx(s_Screen, s_Height, s_Width);

        s_HasColors = has_colors();

        InitColorPairs();
    }

    s_CreationMutex.unlock();
}

Console::~Console()
{
    s_CreationMutex.lock();

    if(--s_InstanceCount == 0)
    {
        s_ThreadTerminator = true;
        s_KeyboardThread->join();
        delete s_KeyboardThread;
        endwin();
    }

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
