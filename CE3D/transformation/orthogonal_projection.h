// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_ORTHOGONAL_PROJECTION_H
#define CE3D_TRANSFORMATION_ORTHOGONAL_PROJECTION_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <vector>

#include "CE3D/util/CE3D_vector.h"
#include "CE3D/util/CE3D_matrix.h"

#include "CE3D/transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A transformation that describes an orthogonal projection.
 */
class OrthogonalProjection : public Transformation
{
public:
    /**
     * Construct an empty orthogonal projection.
     */
    OrthogonalProjection();

    /**
     * Constructs a new orthogonal projection from spanning vectors.
     *
     * @param projection_vectors: The projection vectors of the subspace to
     *                            project on.
     */
    OrthogonalProjection(std::vector<Vector> const& projection_vectors);

    /**
     * Instantiates a new object.
     *
     * @param lookat: The normal of the subspace hyperplane.
     */
    OrthogonalProjection(Vector const& lookat);

    virtual
    ~OrthogonalProjection();

    /**
     * Returns the projection vectors.
     *
     * @return The projection vectors array.
     */
    std::vector<Vector> const&
    GetProjectionVectors() const;

    /**
     * Sets the projection vectors.
     *
     * @param vectors: The projection vectors.
     */
    void
    SetProjectionVectors(std::vector<Vector> const& vectors);

    /**
     * Sets the projection vectors of the n-1 subspace orthonormal to the given
     * direction.
     *
     * @param normal: The normal vector of the projection plane.
     */
    void
    SetProjectionVectors(Vector const& normal);

protected:
    // inherited documentation comment
    virtual void
    UpdateMatrix() const override;

private:
    /**
     * The vectors describing the projection.
     */
    std::vector<Vector> m_ProjectionVectors;
};

}
}

#endif /* CE3D_TRANSFORMATION_ORTHOGONAL_PROJECTION_H */
