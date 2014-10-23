// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_CAMERA_CODE_H
#define CE3D_CAMERA_CAMERA_CODE_H

#include "camera.h"

namespace CE3D {

template <typename MaterialType>
Camera<MaterialType>::~Camera()
{}

template <typename MaterialType>
std::shared_ptr<World<MaterialType> const>
Camera<MaterialType>::GetWorld() const
{
    return m_World;
}

template <typename MaterialType>
void
Camera<MaterialType>::SetWorld(
    std::shared_ptr<World<MaterialType> const> const copy)
{
    m_World = copy;
}

} /* namespace CE3D */

#endif /* CE3D_CAMERA_CODE_H */
