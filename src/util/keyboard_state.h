// This file is part of CE3D. License: GPL3

#ifndef _KEYBOARD_STATE_H
#define _KEYBOARD_STATE_H

#include <curses.h>

#include "util/stdmacro.h"

#include "console/keyboard_thread.h"

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
    KeyboardState* GetInstance();

    inline ModifierKeys GetModifiers() const
    { return m_Modifiers; }
    inline Sign GetContent() const
    { return m_Content; }
};

} /* namespace CE3D */

#endif /* _KEYBOARD_STATE_H */
