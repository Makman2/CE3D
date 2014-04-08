// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_VERTEX_H
#define CE3D_MODEL_VERTEX_H

#include "util/stdinc.h"

namespace CE3D
{

template <std::uint8_t n, typename Material>
class Vertex
{
private:
    Material m_Property;
public:
    inline void
    SetMaterial(Material const& Input)
    { m_Property = Input; }
};

}

#include "model/vertex_code.h"

#endif /* CE3D_MODEL_VERTEX_H */
