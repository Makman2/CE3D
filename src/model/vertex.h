// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_VERTEX_H
#define CE3D_MODEL_VERTEX_H

#include "util/stdinc.h"

#include <boost/container/vector.hpp>

namespace CE3D
{

using VertexIndexType = std::uint16_t;

template <typename t_Material>
class Vertex
{
private:
    /**
     * Contains the material information.
     */
    t_Material m_Property;

    /**
     * Contains the indexes of the vectors that represent the edges of the
     * polygon.
     */
    boost::container::vector<VertexIndexType> m_Vectors;
public:
    inline void
    SetMaterial(t_Material const& Input)
    { m_Property = Input; }
};

}

#include "model/vertex_code.h"

#endif /* CE3D_MODEL_VERTEX_H */
