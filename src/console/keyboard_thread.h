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
private:
    /**
     * Holds the callback functor which is called on every keyboard event.
     */
    Functor<>* m_Callback;
public:
    KeyboardThread();
    void operator()(WINDOW* Screen) const;
    inline void SetCallback(Functor<>* const copy)
    { m_Callback = copy; }
};

}

#endif /* _KEYBOARD_THREAD_H */
