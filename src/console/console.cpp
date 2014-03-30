// This file is part of CE3D. License: GPL3

#include "console/console.h"

#include <stddef.h>

namespace CE3D
{

Console* Console::s_Instance = nullptr;

Console::Console()
{
    m_Screen = initscr();
    // turn of auto echoing
    noecho();
    // get terminal height/width
    getmaxyx(m_Screen, m_Height, m_Width);
}

Console::~Console()
{
    endwin();
}

Console* Console::GetInstance()
{
    if (s_Instance == nullptr)
    {
        s_Instance = new Console();
    }
    return s_Instance;
}

void Console::Flush() const
{
    refresh();
}

void Console::Clear() const
{
    clear();
}

}
