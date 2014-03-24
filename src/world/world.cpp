// This file is part of CE3D. License: GPL3

#include "world.h"


namespace CE3D
{
    boost::ptr_list<Model> World::Models()
    {
        return this->m_Models;
    }

    void World::Transform(const boost::numeric::ublas::matrix<ModelDataType> matrix)
    {
        for (auto it : this->Models())
        {
            it.Transform(matrix);
        }
    }

    void World::Translate(
        const boost::numeric::ublas::vector<ModelDataType> translation)
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

    void World::Scale(const boost::numeric::ublas::vector<ModelDataType> scale)
    {
        for (auto it : this->Models())
        {
            it.Scale(scale);
        }
    }

    void World::Rotate(const boost::numeric::ublas::vector<ModelDataType> planar1,
        const boost::numeric::ublas::vector<ModelDataType> planar2,
        const boost::numeric::ublas::vector<ModelDataType> offset,
        const float angle)
    {
        for (auto it : this->Models())
        {
            it.Rotate(planar1, planar2, offset, angle);
        }
    }
}