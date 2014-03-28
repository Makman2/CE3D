// This file is part of CE3D. License: GPL3

#include "model.h"

#include <boost/numeric/ublas/operation_blocked.hpp>
#include <boost/numeric/ublas/operation.hpp>


namespace CE3D
{


    void Model::Transform(Transformation::Transformation const& transformation)
    {
        Matrix matrix = transformation.GetMatrix();
        for (auto it : GetVectors())
        {
            boost::numeric::ublas::axpy_prod(matrix, it, it, true);
        }	
    }

    void Model::Translate(Transformation::Translation const& translation)
    {
        Vector translationvec = translation.GetTranslation();
        // It's more performant to directly add the vertices together instead of
        // calling the Transform() function and creating a matrix for it.
        for (auto it : GetVectors())
        {
            it += translationvec;
        }
    }

void Model::Scale(const ModelDataType factor)
{
    // And again it's more performant not to use matrices.
    for (auto it : GetVectors())
    {
        it *= factor;
    }
}


void Model::Scale(Transformation::Scale const& scale)
{
    Vector scalevec = scale.GetScale();
    for (auto it : GetVectors())
    {
        it = boost::numeric::ublas::element_prod(it, scalevec);
    }
}

void Model::Rotate(Transformation::Rotation const& rotation)
{
    this->Transform(rotation);
}

}
