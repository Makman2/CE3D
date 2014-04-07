// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_CONSOLE_RENDERER_H
#define CE3D_RENDERER_CONSOLE_RENDERER_H

#include "renderer/renderer.h"

namespace CE3D {

class ConsoleRenderer: public Renderer {
public:
    inline
    ConsoleRenderer() {}
    inline virtual
    ~ConsoleRenderer() {}

    virtual void
    Render(Camera const& camera) const override;
};

} /* namespace CE3D */

#endif /* CE3D_RENDERER_CONSOLE_RENDERER_H */
