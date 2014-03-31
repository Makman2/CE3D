// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_KEYBOARD_STATE_H
#define CE3D_UTIL_KEYBOARD_STATE_H

#include <curses.h>

#include "util/stdinc.h"

namespace CE3D {

using ModifierKeys = enum ModifierKeysEnum
{
    CTRL,
    ALT,
    ENTF //?
};

using Sign = char;

class KeyboardState {
private:
    KeyboardState();
    KeyboardState(KeyboardState const& rhs);

    ModifierKeys m_Modifiers;
    Sign m_Content;

    static KeyboardState* s_Instance;
public:
    KeyboardState*
    GetInstance();

    inline ModifierKeys const&
    GetModifiers() const
    { return m_Modifiers; }

    inline Sign const&
    GetContent() const
    { return m_Content; }
};

} /* namespace CE3D */

#endif /* CE3D_UTIL_KEYBOARD_STATE_H */
