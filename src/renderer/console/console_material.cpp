// This file is part of CE3D. License: GPL3

#include "renderer/console/console_material.h"

namespace CE3D
{

ConsoleMaterial::ConsoleMaterial()
: m_Color(ConsoleColor::BLACK)
{}

ConsoleMaterial::ConsoleMaterial(ConsoleColor InitialColor)
: m_Color(InitialColor)
{}

} /* namespace CE3D */
