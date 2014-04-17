// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H
#define CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H

#include "renderer/renderer.h"

#include "renderer/console/console_material.h"

namespace CE3D {

class ConsoleRenderer: public Renderer<ConsoleMaterial> {
private:
    void
    RenderModel(Model<ConsoleMaterial> Mod) const;
public:
    inline
    ConsoleRenderer() {}
    inline virtual
    ~ConsoleRenderer() {}

    virtual void
    Render(Camera<ConsoleMaterial> const& camera) const override;
};

} /* namespace CE3D */

#endif /* CE3D_RENDERER_CONSOLE_CONSOLE_RENDERER_H */
