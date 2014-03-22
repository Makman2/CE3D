// This file is part of CE3D. License: GPL3

#ifndef _KEYBOARD_STATE_H
#define _KEYBOARD_STATE_H

#include <curses.h>

#include "util/stdmacro.h"

#include "console/keyboard_thread.h"

namespace CE3D {

typedef enum
{
    CTRL,
    ALT,
    ENTF //?
} MODIFIER_KEYS;

typedef char sign;

class KeyboardState {
public:
    static KeyboardState* GetInstance();
private:
    /**
     * This is a singleton.
     */
    KeyboardState();
    KeyboardState(const KeyboardState& rhs);
    ~KeyboardState();

    static KeyboardState* s_Instance;

    friend void KeyboardThread::operator()(WINDOW*) const;

    R_PROPERTY(private, MODIFIER_KEYS, Modifiers);
    R_PROPERTY(private, sign, Content);
};

} /* namespace CE3D */

#endif /* _KEYBOARD_STATE_H */
