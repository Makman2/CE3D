// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_VERTEX_H
#define CE3D_MODEL_VERTEX_H

#include "util/stdinc.h"

#include <boost/container/vector.hpp>

namespace CE3D
{

using VertexIndexType = std::uint32_t;

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
    /**
     * Sets the material.
     *
     * @param Input Your material information.
     */
    inline void
    SetMaterial(t_Material const& Input)
    { m_Property = Input; }

    inline t_Material
    GetMaterial() const
    { return m_Property; }

    inline boost::container::vector<VertexIndexType> const&
    GetVectors() const
    { return m_Vectors; }
    inline boost::container::vector<VertexIndexType>&
    GetVectors()
    { return m_Vectors; }
};

}

#include "model/vertex_code.h"

#endif /* CE3D_MODEL_VERTEX_H */
