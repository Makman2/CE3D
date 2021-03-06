// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_RENDERER_H
#define CE3D_RENDERER_RENDERER_H

#include "CE3D/util/stdinc.h"

#include "CE3D/camera/camera.h"

namespace CE3D
{

/**
 * Represents a renderer that can render the view of a camera.
 */
template <typename MaterialType>
class Renderer
{
private:
    /**
     * Renders a vertex to the render target.
     *
     * @param Vert The vertex to render.
     * @param Mod The model containing the vertex.
     */
    virtual void
    RenderVertex(Vertex<MaterialType> const& Vert,
                 Model<MaterialType>  const& Mod) const = 0;

    /**
     * Invoked before Render().
     *
     * Since Render() is const to the outside your buffer should be mutable.
     */
    virtual void
    PreRender() const = 0;

    /**
     * Invoked after Render().
     *
     * Since Render() is const to the outside your buffer should be mutable.
     */
    virtual void
    PostRender() const = 0;

public:
    /**
     * Renders the view of the given camera.
     *
     * @param camera: The view to render.
     */
    virtual void
    Render(Camera<MaterialType> const& camera) const;

    virtual
    ~Renderer();
};

}

#include "CE3D/renderer/renderer_code.h"

#endif /* CE3D_RENDERER_RENDERER_H */
