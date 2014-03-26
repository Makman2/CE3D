// This file is part of CE3D. License: GPL3

#include "world.h"


namespace CE3D
{
    boost::ptr_list<Model> World::Models()
    {
        return this->m_Models;
    }

    boost::container::vector<boost::numeric::ublas::matrix<ModelDataType>>
        World::Transformations()
    {
        return this->m_Transformations;
    }

    void World::Transform(Transformation::Transformation const& transformation)
    {
        for (auto it : this->Models())
        {
            it.Transform(transformation);
        }
    }

    void World::Translate(Transformation::Translation const& translation)
    {
        for (auto it : this->Models())
        {
            it.Translate(translation);
        }
    }

    void World::Scale(const ModelDataType factor)
    {
        for (auto it : this->Models())
        {
            it.Scale(factor);
        }
    }

    void World::Scale(Transformation::Scale const& scale)
    {
        for (auto it : this->Models())
        {
            it.Scale(scale);
        }
    }

    void World::Rotate(Transformation::Rotation const& rotation)
    {
        for (auto it : this->Models())
        {
            it.Rotate(rotation);
        }
    }
}
