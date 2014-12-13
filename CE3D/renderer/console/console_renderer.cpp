// This file is part of CE3D. License: GPL3

#include "CE3D/renderer/console/console_renderer.h"

#include <stdexcept>

#include "CE3D/world/world.h"

namespace CE3D {

ConsoleRenderer::ConsoleRenderer()
: m_Drawer()
, m_Console()
{}

ConsoleRenderer::~ConsoleRenderer()
{}

void
ConsoleRenderer::PreRender() const
{
    m_Console.Clear();
}

void
ConsoleRenderer::PostRender() const
{
    m_Console.Flush();
}

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
