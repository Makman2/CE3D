// This file is part of CE3D. License: GPL3

#ifndef CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_CODE_H
#define CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_CODE_H

#include "CE3D/camera/orthographic_camera.h"

#include "CE3D/transformation/orthogonal_depth_projection.h"
#include "CE3D/transformation/final_translation.h"

namespace CE3D
{

template <typename MaterialType>
OrthographicCamera<MaterialType>::OrthographicCamera(Vector const& look_at,
                                                     Vector const& worlds_up)
: OrthographicCamera(ZeroVector(look_at.size()), look_at, worlds_up)
{}

template <typename MaterialType>
OrthographicCamera<MaterialType>::OrthographicCamera(Vector const& position,
                                                     Vector const& look_at,
                                                     Vector const& worlds_up)
: OrthographicCamera(position, ConstructProjection(look_at, worlds_up))
{}

template <typename MaterialType>
OrthographicCamera<MaterialType>::OrthographicCamera(
    Vector const& position,
    std::vector<Vector> const& projection)
: m_RealPosition(position)
{
    auto& chain = LinearCamera<MaterialType>::GetTransformationChain();

    chain.template EmplaceBack<Transformation::OrthogonalDepthProjection>(
        projection);
    chain.template EmplaceBack<Transformation::FinalTranslation>(-position);
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
    LinearCamera<MaterialType>::GetTransformationChain()
        .Replace(Transformation::FinalTranslation(-value),
            POSITION_INDEX_FINAL_TRANSLATION);
}

template <typename MaterialType>
std::vector<Vector> const&
OrthographicCamera<MaterialType>::GetProjectionVectors() const
{
    return LinearCamera<MaterialType>::GetTransformationChain()
        .template At<Transformation::OrthogonalDepthProjection>(
            POSITION_INDEX_ORTHOGONAL_DEPTH_PROJECTION)
        .GetProjectionVectors();
}

template <typename MaterialType>
void
OrthographicCamera<MaterialType>::SetProjectionVectors(
    std::vector<Vector> const& vectors)
{
    LinearCamera<MaterialType>::GetTransformationChain()
        .Replace(Transformation::OrthogonalDepthProjection(vectors),
            POSITION_INDEX_ORTHOGONAL_DEPTH_PROJECTION);
}

template <typename MaterialType>
void
OrthographicCamera<MaterialType>::SetProjectionVectors(Vector const& look_at,
                                                       Vector const& worlds_up)
{
    LinearCamera<MaterialType>::GetTransformationChain()
        .Replace(Transformation::OrthogonalDepthProjection(
                ConstructProjection(look_at, worlds_up)),
            POSITION_INDEX_ORTHOGONAL_DEPTH_PROJECTION);
}

template <typename MaterialType>
std::vector<Vector>
OrthographicCamera<MaterialType>::ConstructProjection(
    Vector const& look_at,
    Vector const& worlds_up)
{
    std::vector<Vector> span_list;

    // The vector order is important due to the Gram-Schmidt method performed
    // from OrthogonalDepthProjection.
    span_list.push_back(look_at);
    span_list.push_back(worlds_up);

    return span_list;
}

}

#endif /* CE3D_CAMERA_ORTHOGRAPHIC_CAMERA_CODE_H */
