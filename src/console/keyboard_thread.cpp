// This file is part of CE3D. License: GPL3

#include "keyboard_thread.h"

namespace CE3D
{

KeyboardThread::KeyboardThread()
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
    }
}

}
