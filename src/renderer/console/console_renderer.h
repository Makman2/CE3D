// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H
#define CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H

#include "util/stdinc.h"

#include "renderer/renderer.h"

#include "renderer/console/console_material.h"
#include "renderer/console/console_drawer.h"

namespace CE3D {

class ConsoleRenderer: public Renderer<ConsoleMaterial> {
private:
    /**
     * Helper to draw the things to the real console.
     */
    ConsoleDrawer m_Drawer;
    // Inherited documentation comment
    void
    RenderModel(Model<ConsoleMaterial> Mod) const override;
public:
    inline
    ConsoleRenderer() {}
    inline virtual
    ~ConsoleRenderer() {}
};

} /* namespace CE3D */

#endif /* CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H */
