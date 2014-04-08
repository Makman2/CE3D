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
public:
    /**
     * Renders the view of the given camera.
     *
     * @param camera: The view to render.
     */
    virtual void
    Render(Camera<t_Material> const& camera) const = 0;

    virtual
    ~Renderer() {}
};

}

#endif /* CE3D_RENDERER_RENDERER_H */
