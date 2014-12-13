// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_ORTHOGONAL_DEPTH_PROJECTION_H
#define CE3D_TRANSFORMATION_ORTHOGONAL_DEPTH_PROJECTION_H

#include "CE3D/transformation/orthogonal_projection.h"

namespace CE3D
{
namespace Transformation
{



/**
 * A transformation that describes an orthogonal projection.
 * This transformation also handles the depth calculation of the mapped
 * vectors with an extra-row in the matrix.
 */
class OrthogonalDepthProjection : public OrthogonalProjection
{
protected:

    /**
     * Updates the matrix.
     */
    virtual void
    UpdateMatrix() const override;

public:
    OrthogonalDepthProjection();
    /**
     * @param lookat The lookat vector to initialize the projection with.
     */
    OrthogonalDepthProjection(Vector const& lookat);

    /**
     * Construct orthgonal depth projection from multiple spanning vectors.
     *
     * @param projection_vector: The spanning vectors of the supspace
     *                           hyperplane to poject on.
     */
    OrthogonalDepthProjection(std::vector<Vector> const& projection_vectors);

    virtual
    ~OrthogonalDepthProjection();
};

}
}



#endif /* CE3D_TRANSFORMATION_ORTHOGONAL_DEPTH_PROJECTION_H */
