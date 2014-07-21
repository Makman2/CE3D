// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_CODE_H
#define CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_CODE_H

#include "CE3D/camera/orthographic_camera.h"

#include "CE3D/transformation/orthogonal_depth_projection.h"
#include "CE3D/transformation/translation.h"

namespace CE3D
{

template <typename MaterialType>
OrthographicCamera<MaterialType>::OrthographicCamera()
: m_RealPosition()
, m_LookAt()
{
    auto& chain = LinearCamera<MaterialType>::GetTransformationChain();
    chain.template EmplaceBack<Transformation::OrthogonalDepthProjection>();
    chain.template EmplaceBack<Transformation::Translation>();
}

template <typename MaterialType>
OrthographicCamera<MaterialType>::OrthographicCamera(Vector const& lookAt,
                                                     Vector const& position)
: m_RealPosition(position)
, m_LookAt(lookAt)
{
    auto& chain = LinearCamera<MaterialType>::GetTransformationChain();
    chain.template EmplaceBack<Transformation::OrthogonalDepthProjection>
        (lookAt);
    chain.template EmplaceBack<Transformation::Translation>(-position);
}

template <typename MaterialType>
Vector const&
OrthographicCamera<MaterialType>::GetPosition() const
{
    return m_RealPosition;
}

template <typename MaterialType>
void
OrthographicCamera<MaterialType>::SetPosition(Vector const& value)
{
    m_RealPosition = value;
    LinearCamera<MaterialType>::GetTransformationChain().Replace(
        Transformation::Translation(-value), 1);
}

template <typename MaterialType>
Vector const&
OrthographicCamera<MaterialType>::GetLookAt() const
{
    return m_LookAt;
}

template <typename MaterialType>
void
OrthographicCamera<MaterialType>::SetLookAt(Vector const& value)
{
    LinearCamera<MaterialType>::GetTransformationChain().Replace(
        Transformation::OrthogonalDepthProjection(value), 0);

    m_LookAt = value;
}

}

#endif /* CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_CODE_H */
