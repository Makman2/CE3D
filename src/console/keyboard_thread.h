// This file is part of CE3D. License: GPL3

#ifndef _KEYBOARD_THREAD_H
#define _KEYBOARD_THREAD_H

#include <curses.h>

#include "util/stdmacro.h"

namespace CE3D
{

/**
 * TODO
 */
class KeyboardThread
{
public:
    KeyboardThread();
    operator()() const;
};

}

#endif /* _KEYBOARD_THREAD_H */
