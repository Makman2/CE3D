// This file is part of CE3D. License: GPL3

#ifndef _KEYBOARD_THREAD_H
#define _KEYBOARD_THREAD_H

#include <curses.h>

#include "util/stdmacro.h"

namespace CE3D
{

/**
 * This object provides a functor which is a tread procedure.
 *
 * If you want to have a callback function, just derive from this object and
 * overwrite callback(...). However do not overwrite operator() unless you know
 * what you're doing!
 */
class KeyboardThread
{
public:
    KeyboardThread();
    operator()() const;
protected:
    void callback() const;

};

}

#endif /* _KEYBOARD_THREAD_H */
