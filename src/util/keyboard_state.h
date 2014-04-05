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

class Console;

/**
 * This singleton represents the current keyboard state.
 */
class KeyboardState {
private:
    KeyboardState();
    KeyboardState(KeyboardState const& rhs);

    /**
     * Contains the pressed modifier keys.
     */
    ModifierKeys m_Modifiers;
    /**
     * Contains the pressed keys.
     */
    Sign m_Content;

    /**
     * The one and only instance.
     */
    static KeyboardState* s_Instance;

    /**
     * This changes the keyboard state.
     *
     * This is meant to be changed only by the friend class Console.
     *
     * @param CursesInput the input from curses.
     */
    void SetState(char CursesInput);

    /**
     * The console may set the state.
     */
    friend Console;
public:
    /**
     * Returns the same instance on every invocation.
     *
     * If there is no instance it will be created.
     *
     * @return the instance.
     */
    static KeyboardState*
    GetInstance();

    /**
     * Getter.
     *
     * @return the pressed modifier keys.
     */
    inline ModifierKeys const&
    GetModifiers() const
    { return m_Modifiers; }

    /**
     * Getter.
     *
     * @return The pressed keys.
     */
    inline Sign const&
    GetContent() const
    { return m_Content; }
};

} /* namespace CE3D */

#endif /* CE3D_UTIL_KEYBOARD_STATE_H */
