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
    GENERATE_SINGLETON(KeyboardState);

    R_PROPERTY(private, ModifierKeys, Modifiers);
    R_PROPERTY(private, Sign, Content);
};

} /* namespace CE3D */

#endif /* _KEYBOARD_STATE_H */
