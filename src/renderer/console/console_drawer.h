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
 * responsible for checking what line is above another.
 */
class ConsoleDrawer
{
private:
    mutable Console m_Console;
    ConsoleIdxType m_Width;
    ConsoleIdxType m_Height;
    std::vector<ModelDataType> m_ZBuffer;
    inline ConsoleIdxType
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
     */
    void DrawPoint(Vector const& Point, ConsoleMaterial const& Material) const;
};

} /* namespace CE3D */

#endif /* CE3D_RENDERER_CONSOLE_CONSOLE_DRAWER_H */
