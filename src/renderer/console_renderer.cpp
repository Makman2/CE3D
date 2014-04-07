// This file is part of CE3D. License: GPL3

#include "renderer/console_renderer.h"

#include "world/world.h"

namespace CE3D {

void ConsoleRenderer::Render(const Camera& camera) const
{
    std::unique_ptr<World> World(camera.Paint());
}

} /* namespace CE3D */
