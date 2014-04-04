// This file is part of CE3D. License: GPL3

#include "world/world.h"

namespace CE3D
{

void World::Transform(Transformation::Transformation const& transformation)
{
    for (auto it : GetModels())
    {
        it->Transform(transformation);
    }
}

void World::Translate(Transformation::Translation const& translation)
{
    for (auto it : GetModels())
    {
        it->Translate(translation);
    }
}

void World::Scale(const ModelDataType factor)
{
    for (auto it : GetModels())
    {
        it->Scale(factor);
    }
}

void World::Scale(Transformation::Scale const& scale)
{

    for (auto it : GetModels())
    {
        it->Scale(scale);
    }
}

    void World::Rotate(Transformation::Rotation const& rotation)
    {
        for (auto it : GetModels())
        {
            it->Rotate(rotation);
        }
    }
}
