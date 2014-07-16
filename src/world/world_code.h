// This file is part of CE3D. License: GPL3

#ifndef CE3D_WORLD_WORLD_CODE_H
#define CE3D_WORLD_WORLD_CODE_H

#include "world/world.h"

namespace CE3D
{

template <typename t_Material>
void
World<t_Material>::Transform(
	Transformation::Transformation const& transformation)
{
    for (auto& it : GetModels())
    {
        it->Transform(transformation);
    }
}

template <typename t_Material>
void
World<t_Material>::Translate(
	Transformation::Translation const& translation)
{
    for (auto& it : GetModels())
    {
        it->Translate(translation);
    }
}

template <typename t_Material>
void
World<t_Material>::Scale(
	const ModelDataType factor)
{
    for (auto& it : GetModels())
    {
        it->Scale(factor);
    }
}

template <typename t_Material>
void
World<t_Material>::Scale(
	Transformation::Scale const& scale)
{

    for (auto& it : GetModels())
    {
        it->Scale(scale);
    }
}

template <typename t_Material>
void World<t_Material>::Rotate(
	Transformation::Rotation const& rotation)
{
    for (auto& it : GetModels())
    {
        it->Rotate(rotation);
    }
}

}

#endif /* CE3D_WORLD_WORLD_CODE_H */
