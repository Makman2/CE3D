// This file is part of CE3D. License: GPL3

#include "renderer/console/console_drawer.h"

#include <stdexcept>

namespace CE3D {

ConsoleDrawer::ConsoleDrawer()
: m_Console()
, m_ZBuffer(0, -1.0/0.0)
{
    m_Width = m_Console.GetWidth();
    m_Height = m_Console.GetHeight();
    m_ZBuffer.resize(m_Width*m_Height, -1.0/0.0);
}

void ConsoleDrawer::DrawPoint(Vector const& Point,
       __attribute__((unused))ConsoleMaterial const& Material) const
{
    if (Point.size() < 3)
    {
        throw std::invalid_argument(
                "Vector must have at least three components.");
    }

    if (Point[0] >= m_Width || Point[1] >= m_Height)
    {
        return;
    }

    ConsoleIdxType x, y;
    x = static_cast<ConsoleIdxType>(Point[0]);
    y = static_cast<ConsoleIdxType>(Point[1]);
    if (m_ZBuffer[CalculateIndex(x, y)] > Point[2])
    {
        return;
    }

    ConsoleStringAttributes Attr;
    Attr.SetColor(Material.GetColor(), ConsoleColor::WHITE);
    m_Console.WriteChar(x, y, '.');
}

} /* namespace CE3D */
