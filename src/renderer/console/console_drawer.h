// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_CONSOLE_CONSOLE_DRAWER_H
#define CE3D_RENDERER_CONSOLE_CONSOLE_DRAWER_H

#include "util/stdinc.h"

#include "console/console.h"
#include "renderer/console/console_material.h"
#include "util/CE3D_vector.h"

namespace CE3D {

/**
 * Draws abstract things like lines and points to the console. It also is
 * responsible for checking what point is above another.
 */
class ConsoleDrawer
{
private:
    /**
     * The console to draw on.
     */
    mutable Console m_Console;
    /**
     * The width of the console.
     */
    ConsoleIdxType m_Width;
    /**
     * The height of the console.
     */
    ConsoleIdxType m_Height;
    /**
     * A buffer for the z values.
     *
     * If a new point wants to be drawn and there is already one it will only
     * overwrite the old point if he has a higher z value.
     */
    std::vector<ModelDataType> m_ZBuffer;
    /**
     * Calculates the index for the z buffer array.
     *
     * @param x column
     * @param y line
     * @return the index
     */
    ConsoleIdxType
    CalculateIndex(ConsoleIdxType const x, ConsoleIdxType const y) const
    { return m_Width*x + y; }
public:
    /**
     * Default constructor.
     *
     * Will also retrieve the current console size.
     */
    ConsoleDrawer();
    /**
     * Draws a point to the console (if there is no other "thing" above)
     *
     * @param Point The point
     * @param Material The material information for the point
     */
    void DrawPoint(Vector const& Point, ConsoleMaterial const& Material) const;
};

} /* namespace CE3D */

#endif /* CE3D_RENDERER_CONSOLE_CONSOLE_DRAWER_H */
