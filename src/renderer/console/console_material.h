// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_CONSOLE_CONSOLE_MATERIAL_H
#define CE3D_RENDERER_CONSOLE_CONSOLE_MATERIAL_H

#include "util/stdinc.h"

#include "console/console_string_attributes.h"

namespace CE3D {

class ConsoleMaterial {
private:
    /**
     * The color of this material.
     */
    ConsoleColor m_Color;
public:
    /**
     * Initializes a black material.
     */
    ConsoleMaterial();
    /**
     * Custom constructor.
     *
     * @param InitialColor The color for the material.
     */
    ConsoleMaterial(ConsoleColor InitialColor);
    inline virtual
    ~ConsoleMaterial() {}
};

} /* namespace CE3D */

#endif /* CE3D_RENDERER_CONSOLE_CONSOLE_MATERIAL_H */
