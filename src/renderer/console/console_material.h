// This file is part of CE3D. License: GPL3

#ifndef CE3D_RENDERER_CONSOLE_MATERIAL_H
#define CE3D_RENDERER_CONSOLE_MATERIAL_H

#include "console/console_string_attributes.h"

namespace CE3D {

class ConsoleMaterial {
private:
    ConsoleColor m_Color;
public:
    ConsoleMaterial();
    inline virtual
    ~ConsoleMaterial() {}
};

} /* namespace CE3D */

#endif /* CE3D_RENDERER_CONSOLE_MATERIAL_H */
