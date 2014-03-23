// This file is part of CE3D. License: GPL3

#ifndef _KEYBOARD_THREAD_H
#define _KEYBOARD_THREAD_H

#include <curses.h>

#include "util/stdmacro.h"

#include "util/functor.h"

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
    void SetCallback(Functor<>* copy);
private:
    /**
     * Holds the callback functor which is called on every keyboard event.
     *
     * We can't use W_PROPERTY, TODO research on the const error
     */
    PROPERTY(private, Functor<>*, Callback);
};

}

#endif /* _KEYBOARD_THREAD_H */
