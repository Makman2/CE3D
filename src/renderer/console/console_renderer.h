// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H
#define CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H

#include "util/stdinc.h"

#include "renderer/renderer.h"

#include "renderer/console/console_material.h"
#include "renderer/console/console_drawer.h"
#include "console/console.h"

namespace CE3D {

/**
 * A renderer for the curses console.
 */
class ConsoleRenderer: public Renderer<ConsoleMaterial> {
private:
    /**
     * Helper to draw the things to the real console.
     */
    ConsoleDrawer m_Drawer;
    /**
     * Console for clearing and refreshing.
     */
    Console m_Console;

    // Inherited documentation comment
    virtual inline void
    ClearBuffer() const
    { m_Console.Clear(); }
    // Inherited documentation comment
    virtual inline void
    FlushBuffer() const
    { m_Console.Flush(); }
    // Inherited documentation comment
    void
    RenderVertex(Vertex<ConsoleMaterial> const& Vert,
                 Model<ConsoleMaterial> const& Mod) const override;
public:
    inline
    ConsoleRenderer() {}
    inline virtual
    ~ConsoleRenderer() {}
};

} /* namespace CE3D */

#endif /* CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H */
