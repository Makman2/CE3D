// This file is part of CE3D. License: GPL3

#include "console.h"

#include <stddef.h>

namespace CE3D
{

Console* Console::s_instance = NULL;

Console::Console()
{
    m_Screen = initscr();
    noecho();
    getmaxyx(m_Screen, m_Height, m_Width);
}

Console* Console::GetInstance()
{
    if (s_instance == NULL)
    {
        s_instance = new Console();
    }
    return s_instance;
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
