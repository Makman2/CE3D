// This file is part of CE3D. License: GPL3

#include "keyboard_thread.h"

namespace CE3D
{

KeyboardThread::KeyboardThread()
 : m_Callback(nullptr)
{
}

void KeyboardThread::operator ()(WINDOW* Screen) const
{
    char c;

    keypad(Screen, true);
    cbreak();

    while (1)
    {
        c = getch();
        // TODO set keyboard state
        if (m_Callback != nullptr)
        {
            (*m_Callback)();
        }
    }
}

}
