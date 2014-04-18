// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_CONSOLE_CONSOLE_DRAWER_H
#define CE3D_RENDERER_CONSOLE_CONSOLE_DRAWER_H

#include "util/stdinc.h"

#include "console/console.h"

namespace CE3D {

class ConsoleDrawer
{
private:
    Console m_Console;
public:
    /**
     * Default constructor.
     *
     * Will also retrieve the current console size.
     */
    ConsoleDrawer();
};

} /* namespace CE3D */

#endif /* CE3D_RENDERER_CONSOLE_CONSOLE_DRAWER_H */
