// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_MODEL_CODE_H
#define CE3D_MODEL_MODEL_CODE_H

#include "CE3D/model/model.h"

#include <boost/numeric/ublas/operation_blocked.hpp>
#include <boost/numeric/ublas/operation.hpp>


namespace CE3D
{

template <typename t_Material>
Model<t_Material>::Model()
: m_Vectors()
, m_Vertices()
, m_Visible(true)
, m_Name("")
{ }

template <typename t_Material>
void Model<t_Material>::Transform
(Transformation::Transformation const& transformation)
{
    Matrix matrix = transformation.GetMatrix();
    Vector temp(matrix.size1());
    for (auto it : GetVectors())
    {
        boost::numeric::ublas::axpy_prod(matrix, it, temp, true);
        it = temp;
    }
}

template <typename t_Material>
void Model<t_Material>::Translate
(Transformation::Translation const& translation)
{
    Vector translationvec = translation.GetTranslation();
    // It's more performant to directly add the vertices together instead of
    // calling the Transform() function and creating a matrix for it.
    for (auto it : GetVectors())
    {
        it += translationvec;
    }
}

template <typename t_Material>
void Model<t_Material>::Scale(const ModelDataType factor)
{
    // And again it's more performant not to use matrices.
    for (auto it : GetVectors())
    {
        it *= factor;
    }
}

template <typename t_Material>
void Model<t_Material>::Scale(Transformation::Scale const& scale)
{
    Vector scalevec = scale.GetScale();
    for (auto it : GetVectors())
    {
        it = boost::numeric::ublas::element_prod(it, scalevec);
    }
}

template <typename t_Material>
void Model<t_Material>::Rotate(Transformation::Rotation const& rotation)
{
    this->Transform(rotation);
}

}

#endif /* CE3D_MODEL_MODEL_CODE_H */
