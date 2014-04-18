// This file is part of CE3D. License: GPL3

#include "renderer/console/console_drawer.h"

namespace CE3D {

ConsoleDrawer::ConsoleDrawer()
: m_Console()
{
    m_Height = m_Console.GetHeight();
    m_Width = m_Console.GetWidth();
}

void ConsoleDrawer::DrawPoint(__attribute__((unused))Vector const& Point,
       __attribute__((unused))ConsoleMaterial const& Material) const
{
    // UNIMPLEMENTED - for now!
}

} /* namespace CE3D */
