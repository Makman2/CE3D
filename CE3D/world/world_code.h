// This file is part of CE3D. License: GPL3

#ifndef CE3D_WORLD_WORLD_CODE_H
#define CE3D_WORLD_WORLD_CODE_H

#include "CE3D/world/world.h"

namespace CE3D
{

template <typename MaterialType>
void
World<MaterialType>::Transform(
    Transformation::Transformation const& transformation)
{
    for (auto& it : GetModels())
    {
        it->Transform(transformation);
    }
}

template <typename MaterialType>
void
World<MaterialType>::Translate(
    Transformation::Translation const& translation)
{
    for (auto& it : GetModels())
    {
        it->Translate(translation);
    }
}

template <typename MaterialType>
void
World<MaterialType>::Scale(
    const ModelDataType factor)
{
    for (auto& it : GetModels())
    {
        it->Scale(factor);
    }
}

template <typename MaterialType>
void
World<MaterialType>::Scale(
    Transformation::Scale const& scale)
{

    for (auto& it : GetModels())
    {
        it->Scale(scale);
    }
}

template <typename MaterialType>
void World<MaterialType>::Rotate(
    Transformation::Rotation const& rotation)
{
    for (auto& it : GetModels())
    {
        it->Rotate(rotation);
    }
}

}

#endif /* CE3D_WORLD_WORLD_CODE_H */
