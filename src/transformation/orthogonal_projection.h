// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_ORTHOGONAL_PROJECTION_H
#define CE3D_TRANSFORMATION_ORTHOGONAL_PROJECTION_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <array>

#include "util/stdmacro.h"

#include "transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{

    
template <std::size_t N>

/**
 * A transformation that describes an orthogonal projection.
 */
class OrthogonalProjection : public Transformation
{
private:

    std::array<Vector, N> m_ProjectionVectors;
    
    void
    UpdateMatrix();

public:

    /**
     * Returns the projection vectors.
     *
     * @return The projection vectors array.
     */
    inline std::array<Vector, N> const&
    GetProjectionVectors() const
    { return m_ProjectionVectors; }

    /**
     * Sets the projection vectors.
     *
     * @param vectors: The projection vectors.
     */
    void
    SetProjectionVectors(std::array<Vector, N> const& vectors);

    /**
     * Sets the projection vectors of the n-1 subspace orthogonal to the given
     * direction.
     *
     * @param direction: The direction in which the projection plane is orientated.
     */
    void
    SetProjectionVectors(Vector const& direction);

};

}
}



#endif /* CE3D_TRANSFORMATION_ORTHOGONAL_PROJECTION_H */
