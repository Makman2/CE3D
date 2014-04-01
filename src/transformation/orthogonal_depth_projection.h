// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_ORTHOGONAL_DEPTH_PROJECTION_H
#define CE3D_TRANSFORMATION_ORTHOGONAL_DEPTH_PROJECTION_H

#include "transformation/orthogonal_depth_projection.h"

#include "transformation/orthogonal_projection.h"

namespace CE3D
{
namespace Transformation
{

    

/**
 * A transformation that describes an orthogonal projection.
 */
class OrthogonalDepthProjection : public OrthogonalProjection
{
protected:

    /**
     * Updates the matrix.
     */
    virtual void
    UpdateMatrix();
};

}
}



#endif /* CE3D_TRANSFORMATION_ORTHOGONAL_DEPTH_PROJECTION_H */
