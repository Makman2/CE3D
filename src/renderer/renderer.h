// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_RENDERER_H
#define CE3D_RENDERER_RENDERER_H

#include "util/stdinc.h"

#include "camera/camera.h"

namespace CE3D
{

/**
 * Represents a renderer that can render the view of a camera.
 */
template <typename t_Material>
class Renderer
{
private:
    /**
     * Renders a whole model to the console.
     *
     * @param Mod The model to render.
     */
    virtual void
    RenderModel(Model<t_Material> Mod) const = 0;
public:
    /**
     * Renders the view of the given camera.
     *
     * @param camera: The view to render.
     */
    virtual void
    Render(Camera<t_Material> const& camera) const;

    virtual
    ~Renderer() {}
};

}

#include "renderer/renderer_code.h"

#endif /* CE3D_RENDERER_RENDERER_H */
