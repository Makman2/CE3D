// This file is part of CE3D. License: GPL3

#include "CE3D/renderer/console/console_material.h"

namespace CE3D
{

ConsoleMaterial::ConsoleMaterial()
: m_Color(ConsoleColor::BLACK)
{}

ConsoleMaterial::ConsoleMaterial(ConsoleColor InitialColor)
: m_Color(InitialColor)
{}

ConsoleMaterial::~ConsoleMaterial()
{}

ConsoleColor
ConsoleMaterial::GetColor() const
{
    return m_Color;
}

void
ConsoleMaterial::SetColor(ConsoleColor ForegroundColor)
{
    m_Color = ForegroundColor;
}

} /* namespace CE3D */
