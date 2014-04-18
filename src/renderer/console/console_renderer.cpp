// This file is part of CE3D. License: GPL3

#include "renderer/console/console_renderer.h"

#include <stdexcept>

#include "world/world.h"

namespace CE3D {

void ConsoleRenderer::RenderModel(Model<ConsoleMaterial> Mod) const
{
    for (auto& Vertex : Mod.GetVertices())
    {
        auto& Vectors = Vertex.GetVectors();
        switch (Vectors.size())
        {
        case 1:
        case 2:
        case 3:
        default:
            throw std::length_error("Unsupported vector count.");
        }
    }
}

} /* namespace CE3D */
