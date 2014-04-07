// This file is part of CE3D. License: GPL3

#include "renderer/console_renderer.h"

#include "world/world.h"

namespace CE3D {

void ConsoleRenderer::Render(const Camera& camera) const
{
    std::unique_ptr<World> World(camera.Paint());

    for (auto& it : World->GetModels())
    {
        switch (it->GetModelType())
        {
        case POINT:
            break;
        case LINE:
            break;
        case TRIANGLE:
            break;
        case UNKNOWN:
        default:
            break;
        }
    }
}

} /* namespace CE3D */
