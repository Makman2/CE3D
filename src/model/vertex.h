// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_VERTEX_H
#define CE3D_MODEL_VERTEX_H

#include "util/stdinc.h"

namespace CE3D
{

using VertexIndexType = std::uint16_t;

template <std::uint8_t n, typename Material>
class Vertex
{
private:
    /**
     * Contains the material information.
     */
    Material m_Property;

    /**
     * Contains the vectors that represent the edges of the polygon.
     */
    VertexIndexType m_Vectors[n];
public:
    inline void
    SetMaterial(Material const& Input)
    { m_Property = Input; }
};

}

#include "model/vertex_code.h"

#endif /* CE3D_MODEL_VERTEX_H */
