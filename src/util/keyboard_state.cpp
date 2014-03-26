// This file is part of CE3D. License: GPL3

#include "keyboard_state.h"

namespace CE3D {

KeyboardState* KeyboardState::GetInstance()
{
    if (s_Instance == nullptr)
    {
        s_Instance = new KeyboardState();
    }
    return s_Instance;
}

} /* namespace CE3D */
