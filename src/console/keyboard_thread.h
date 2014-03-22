// This file is part of CE3D. License: GPL3

#ifndef _KEYBOARD_THREAD_H
#define _KEYBOARD_THREAD_H

#include <curses.h>

#include "util/stdmacro.h"

namespace CE3D
{

/**
 * This object provides a functor which is a tread procedure.
 */
class KeyboardThread
{
public:
    KeyboardThread();
    void operator()(WINDOW* Screen) const;
private:
};

}

#endif /* _KEYBOARD_THREAD_H */
