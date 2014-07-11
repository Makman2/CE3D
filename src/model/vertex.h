// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_VERTEX_H
#define CE3D_MODEL_VERTEX_H

#include "util/stdinc.h"

#include <boost/container/vector.hpp>

namespace CE3D
{

using VertexIndexType = std::uint32_t;

/**
 * A "thing" out of which a model is made.
 *
 * A vertex is typically a point, a line or a triangle. It holds also some
 * other properties via the template t_Material. (May contain transparency,
 * color and all these things.)
 */
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

    /**
     * Getter.
     *
     * @return the material.
     */
    inline t_Material
    GetMaterial() const
    { return m_Property; }

    /**
     * Getter (const).
     *
     * @return the vectors of this vertex (const)
     */
    inline boost::container::vector<VertexIndexType> const&
    GetVectors() const
    { return m_Vectors; }

    /**
     * Getter.
     *
     * @return the vectors of this vertex
     */
    inline boost::container::vector<VertexIndexType>&
    GetVectors()
    { return m_Vectors; }
};

}

#include "model/vertex_code.h"

#endif /* CE3D_MODEL_VERTEX_H */
