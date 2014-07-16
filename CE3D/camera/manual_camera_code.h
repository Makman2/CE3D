// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_MANUAL_CAMERA_CODE_H
#define CE3D_CAMERA_MANUAL_CAMERA_CODE_H

#include "manual_camera.h"

namespace CE3D {

template <typename MaterialType>
Transformation::TransformationChain&
ManualCamera<MaterialType>::GetTransformationChain()
{
    return LinearCamera::GetTransformationChain();
}

}

#endif /* CE3D_CAMERA_MANUAL_CAMERA_CODE_H */
