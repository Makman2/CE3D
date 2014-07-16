// This file is part of CE3D. License: GPL3

#include "CE3D/util/keyboard_state.h"

namespace CE3D {

KeyboardState* KeyboardState::s_Instance = nullptr;

KeyboardState::KeyboardState()
{}

KeyboardState* KeyboardState::GetInstance()
{
    if (s_Instance == nullptr)
    {
        s_Instance = new KeyboardState();
    }
    return s_Instance;
}

} /* namespace CE3D */
