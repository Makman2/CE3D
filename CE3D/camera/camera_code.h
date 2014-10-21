// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_CAMERA_CODE_H
#define CE3D_CAMERA_CAMERA_CODE_H

#include "camera.h"

namespace CE3D {

template <typename t_Material>
Camera<t_Material>::~Camera()
{}

template <typename t_Material>
std::shared_ptr<World<t_Material> const>
Camera<t_Material>::GetWorld() const
{
    return m_World;
}

template <typename t_Material>
void
Camera<t_Material>::SetWorld(
    std::shared_ptr<World<t_Material> const> const copy)
{
    m_World = copy;
}

} /* namespace CE3D */

#endif /* CE3D_CAMERA_CODE_H */
