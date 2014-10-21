// This file is part of CE3D. License: GPL3

#include "CE3D/console/console_string_attributes.h"

namespace CE3D {

ConsoleStringAttributes::ConsoleStringAttributes()
: m_ColorPairId(0)
, m_Attributes(0)
{}

ConsoleStringAttributes::~ConsoleStringAttributes()
{}

std::uint32_t
ConsoleStringAttributes::GetCursesRepresentation() const
{
    return m_Attributes | COLOR_PAIR(m_ColorPairId);
}

void
ConsoleStringAttributes::SetColor(ConsoleColor const Foreground,
                                  ConsoleColor const Background)
{
    m_ColorPairId = ColorPairIndex(Foreground, Background);
}

void
ConsoleStringAttributes::SetColor(std::uint8_t const ColorPairId)
{
    m_ColorPairId = ColorPairId;
}

} /* namespace CE3D */
