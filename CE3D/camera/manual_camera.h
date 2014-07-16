// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_MANUAL_CAMERA_H
#define CE3D_CAMERA_MANUAL_CAMERA_H

#include "camera/linear_camera.h"

namespace CE3D {

template <typename MaterialType>
class ManualCamera : public LinearCamera<MaterialType>
{
public:
    /**
     * Returns a chain of transformations applied sequentially on Paint().
     *
     * @returns The transformation chain.
     */
    Transformation::TransformationChain&
    GetTransformationChain();
};

}
#endif /* CE3D_CAMERA_MANUAL_CAMERA_H */
