// This file is part of CE3D. License: GPL3

#include "transformation/orthogonal_depth_projection.h"
#include "util/boost_extensions.h"

namespace CE3D
{
namespace Transformation
{

void OrthogonalDepthProjection::UpdateMatrix()
{
    OrthogonalProjection::UpdateMatrix();

    // Append matrix row for depth/distance calculation.

}


}
}
