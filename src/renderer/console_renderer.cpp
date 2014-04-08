// This file is part of CE3D. License: GPL3

#include "renderer/console_renderer.h"

#include "world/world.h"

namespace CE3D {

void ConsoleRenderer::Render(const Camera<ConsoleMaterial>& camera) const
{
    std::unique_ptr<World<ConsoleMaterial> > World(camera.Paint());

    for (auto& it : World->GetModels())
    {
        if (it->IsVisible())
        {
            break;
        }
    }
}

} /* namespace CE3D */
