// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_VERTEX_H
#define CE3D_MODEL_VERTEX_H

#include "CE3D/util/stdinc.h"

#include <boost/container/vector.hpp>

namespace CE3D
{

using VertexIndexType = std::uint32_t;

/**
 * A "thing" out of which a model is made.
 *
 * A vertex is typically a point, a line or a triangle. It holds also some
 * other properties via the template MaterialType. (May contain transparency,
 * color and all these things.)
 */
template <typename MaterialType>
class Vertex
{
private:
    /**
     * Contains the material information.
     */
    MaterialType m_Property;

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
    void
    SetMaterial(MaterialType const& Input)
    { m_Property = Input; }

    /**
     * Getter.
     *
     * @return the material.
     */
    MaterialType
    GetMaterial() const
    { return m_Property; }

    /**
     * Getter (const).
     *
     * @return the vectors of this vertex (const)
     */
    boost::container::vector<VertexIndexType> const&
    GetVectors() const
    { return m_Vectors; }

    /**
     * Getter.
     *
     * @return the vectors of this vertex
     */
    boost::container::vector<VertexIndexType>&
    GetVectors()
    { return m_Vectors; }
};

}

#include "CE3D/model/vertex_code.h"

#endif /* CE3D_MODEL_VERTEX_H */
