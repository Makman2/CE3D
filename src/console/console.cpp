// This file is part of CE3D. License: GPL3

#include "console.h"

#include <stddef.h>

namespace CE3D
{

Console* Console::s_instance = NULL;

Console* Console::GetInstance()
{
    if (s_instance == NULL)
    {
        s_instance = new Console();
    }
    return s_instance;
}

}
