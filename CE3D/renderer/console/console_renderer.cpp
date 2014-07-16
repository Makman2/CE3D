// This file is part of CE3D. License: GPL3

#include "renderer/console/console_renderer.h"

#include <stdexcept>

#include "world/world.h"

namespace CE3D {

void ConsoleRenderer::RenderVertex(Vertex<ConsoleMaterial> const& Vert,
                                   Model<ConsoleMaterial>  const& Mod) const
{
    auto& VectorIndices = Vert.GetVectors();
    auto& Vectors = Mod.GetVectors();

    switch (VectorIndices.size())
    {
    case 1:
        m_Drawer.DrawPoint(Vectors[VectorIndices[0]], Vert.GetMaterial());
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        throw std::length_error("Unsupported vector count.");
    }
}

} /* namespace CE3D */
