// This file is part of CE3D. License: GPL3

#include "keyboard_thread.h"

namespace CE3D
{

KeyboardThread::KeyboardThread()
 : m_Callback(NULL)
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
        if (m_Callback != NULL)
        {
            (*m_Callback)();
        }
    }
}

void KeyboardThread::SetCallback(Functor<>* copy)
{
    m_Callback = copy;
}

}
