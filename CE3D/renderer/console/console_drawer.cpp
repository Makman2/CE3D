// This file is part of CE3D. License: GPL3

#include "CE3D/renderer/console/console_drawer.h"

#include <stdexcept>
#include <algorithm>

namespace CE3D {

ConsoleDrawer::ConsoleDrawer()
: m_Console()
, m_ZBuffer(0, -1.0/0.0)
{
    m_Width = m_Console.GetWidth();
    m_Height = m_Console.GetHeight();
    m_ZBuffer.resize(m_Width*m_Height, -1.0/0.0);
}

void ConsoleDrawer::DrawPoint(Vector const&          point,
      __attribute__((unused)) ConsoleMaterial const& material) const
{
    if (point.size() < 3)
    {
        throw std::invalid_argument(
            "Vector must have at least three components.");
    }

    if (point[0] >= m_Width || point[1] >= m_Height)
    {
        return;
    }

    ConsoleIdxType x, y;
    x = static_cast<ConsoleIdxType>(point[0]);
    y = static_cast<ConsoleIdxType>(point[1]);
    if (m_ZBuffer[CalculateIndex(x, y)] > point[2])
    {
        return;
    }

    ConsoleStringAttributes Attr;
    Attr.SetColor(ConsoleColor::GREEN, ConsoleColor::WHITE);
    m_Console.WriteChar(x, y, Attr, '.');
}

void
ConsoleDrawer::DrawLine(Vector const&          p1,
                        Vector const&          p2,
__attribute__((unused)) ConsoleMaterial const& material) const
{
    // TODO: Trigger log warning when dimension of p1 or p2 is bigger than two,
    // more is just ignored (p1.size() > 2 || p2.size() > 2).

    float divisor = 1.0f / static_cast<float>(p1[0] - p2[0]);

    if (std::isinf(divisor))
    {
        // Special case: Complete vertical line.

        // Why min() + 1? because the line should start at the bottom of the
        // char-box. The char '|' starts from top, so we leave the first one
        // out.
        for (int y = std::min(p1[1], p2[1]) + 1;
             y <= std::max(p1[1], p2[1]);
             y++)
        {
            m_Console.WriteChar(p1[0], y, '|');
        }

        return;
    }

    // Linear function parameters. f(x) = gradient * x + y_axis_intersect.
    float gradient = divisor * (p1[1] - p2[1]);

    // Catch NaN-case when points do equal, so we don't need to draw anything.
    if (isnan(gradient))
    {
        return;
    }

    float y_axis_intersect = divisor * (p1[0] * p2[1] - p2[0] * p1[1]);

    // At 45 degree linear function angle a switch between the normal linear
    // function and the inverse linear function is needed so no holes/spaces
    // are written into the line.
    if (std::fabs(gradient) > 1)
    {
        // Inverse linear function approach.
        int y0 = std::min(p1[1], p2[1]);
        int fy;
        int fy2 = std::round((y0 - y_axis_intersect) / gradient);
        for (int y = y0 + 1; y <= std::max(p1[1], p2[1]); y++)
        {
            fy = fy2;
            fy2 = std::round((y - y_axis_intersect) / gradient);

            if (fy < fy2)
            {
                m_Console.WriteChar(fy, y, '\\');
            }
            else if (fy == fy2)
            {
                m_Console.WriteChar(fy, y, '|');
            }
            else
            {
                m_Console.WriteChar(fy, y, '/');
            }
        }
    }
    else
    {
        // Standard line handling (normal linear function approach).
        int x0 = std::min(p1[0], p2[0]);
        int fx;
        int fx2 = std::round(x0 * gradient + y_axis_intersect);
        for (int x = x0 + 1; x <= std::max(p1[0], p2[0]); x++)
        {
            fx = fx2;
            fx2 = std::round(x * gradient + y_axis_intersect);

            if (fx < fx2)
            {
                m_Console.WriteChar(x, fx + 1, '\\');
            }
            else if (fx == fx2)
            {
                m_Console.WriteChar(x, fx, '_');
            }
            else
            {
                m_Console.WriteChar(x, fx, '/');
            }
        }
    }
}

} /* namespace CE3D */
