// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_ORTHOGONAL_DEPTH_PROJECTION_H
#define CE3D_TRANSFORMATION_ORTHOGONAL_DEPTH_PROJECTION_H

#include "transformation/orthogonal_projection.h"

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
    virtual
    ~OrthogonalDepthProjection() {}
};

}
}



#endif /* CE3D_TRANSFORMATION_ORTHOGONAL_DEPTH_PROJECTION_H */
