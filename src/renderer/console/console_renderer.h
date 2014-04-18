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
    ConsoleDrawer m_Drawer;
    /**
     * Renders a whole model to the console.
     *
     * @param Mod The model to render.
     */
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
