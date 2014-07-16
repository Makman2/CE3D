// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_RENDERER_CODE_H
#define CE3D_RENDERER_RENDERER_CODE_H

#include "CE3D/renderer/renderer.h"

#include "CE3D/console/console.h"

namespace CE3D {

template <typename t_Material>
void Renderer<t_Material>::Render(const Camera<t_Material>& camera) const
{
    ClearBuffer();

    typename std::unique_ptr<World<t_Material> > World(camera.Paint());

    for (auto& it : World->GetModels())
    {
        if (!it->IsVisible())
        {
            continue;
        }
        for (auto& Vertex : it->GetVertices())
        {
            RenderVertex(Vertex, *it);
        }
    }

    FlushBuffer();
}

} /* namespace CE3D */

#endif /* CE3D_RENDERER_RENDERER_H */
