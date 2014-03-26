// This file is part of CE3D. License: GPL3

#include "world.h"


namespace CE3D
{

boost::container::vector<boost::numeric::ublas::matrix<ModelDataType>>
    World::Transformations()
{
    return m_Transformations;
}

void World::Transform(const boost::numeric::ublas::matrix<ModelDataType> matrix)
{
    for (auto it : GetModels())
    {
        it.Transform(matrix);
    }
}

void World::Translate(
    const boost::numeric::ublas::vector<ModelDataType> translation)
{
    for (auto it : GetModels())
    {
        it.Translate(translation);
    }
}

void World::Scale(const ModelDataType factor)
{
    for (auto it : GetModels())
    {
        it.Scale(factor);
    }
}

void World::Scale(const boost::numeric::ublas::vector<ModelDataType> scale)
{
    for (auto it : GetModels())
    {
        it.Scale(scale);
    }
}

void World::Rotate(const boost::numeric::ublas::vector<ModelDataType> planar1,
    const boost::numeric::ublas::vector<ModelDataType> planar2,
    const boost::numeric::ublas::vector<ModelDataType> offset,
    const float angle)
{
    for (auto it : GetModels())
    {
        it.Rotate(planar1, planar2, offset, angle);
    }
}

}
