// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H
#define CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H

#include "CE3D/util/stdinc.h"

#include "CE3D/renderer/renderer.h"

#include "CE3D/renderer/console/console_material.h"
#include "CE3D/renderer/console/console_drawer.h"
#include "CE3D/console/console.h"

namespace CE3D {

/**
 * A renderer for the curses console.
 */
class ConsoleRenderer: public Renderer<ConsoleMaterial> {
public:
    ConsoleRenderer();
    virtual

    ~ConsoleRenderer();

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
    virtual void
    PreRender() const override;

    // Inherited documentation comment
    virtual void
    PostRender() const override;

    // Inherited documentation comment
    void
    RenderVertex(Vertex<ConsoleMaterial> const& Vert,
                 Model<ConsoleMaterial>  const& Mod) const override;
};

} /* namespace CE3D */

#endif /* CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H */
