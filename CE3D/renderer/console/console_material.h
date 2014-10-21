// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_CONSOLE_CONSOLE_MATERIAL_H
#define CE3D_RENDERER_CONSOLE_CONSOLE_MATERIAL_H

#include "CE3D/util/stdinc.h"

#include "CE3D/console/console_string_attributes.h"

namespace CE3D {

/**
 * A material for the curses console.
 */
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

    virtual
    ~ConsoleMaterial();

    /**
     * Getter.
     *
     * @return The foreground color.
     */
    ConsoleColor
    GetColor() const;

    /**
     * Setter for the foreground color of the vertex.
     *
     * @param ForegroundColor The color.
     */
    void
    SetColor(ConsoleColor ForegroundColor);

};

} /* namespace CE3D */

#endif /* CE3D_RENDERER_CONSOLE_CONSOLE_MATERIAL_H */
