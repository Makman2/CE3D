// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_LINEAR_CAMERA_CODE_H
#define CE3D_CAMERA_LINEAR_CAMERA_CODE_H

#include "camera/linear_camera.h"

namespace CE3D {

template <typename MaterialType>
LinearCamera<MaterialType>::LinearCamera()
: m_TransformationChain()
{}

template <typename MaterialType>
LinearCamera<MaterialType>::~LinearCamera()
{}

template <typename MaterialType>
Transformation::TransformationChain&
LinearCamera<MaterialType>::GetTransformationChain()
{
    return m_TransformationChain;
}
    
template <typename MaterialType>
std::unique_ptr<World<MaterialType> >
LinearCamera<MaterialType>::Paint() const
{
    std::unique_ptr<World<MaterialType> >
    TransformedWorld(new World<MaterialType>(*(this->GetWorld())));

    if (!m_TransformationChain.IsEmpty())
    {
        TransformedWorld->Transform(m_TransformationChain);
    }

    return std::move(TransformedWorld);
}

} /* namespace CE3D */

#endif /* CE3D_CAMERA_LINEAR_CAMERA_CODE_H */
