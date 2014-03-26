// This file is part of CE3D. License: GPL3

#include "model.h"

#include <boost/numeric/ublas/operation_blocked.hpp>
#include <boost/numeric/ublas/operation.hpp>


namespace CE3D
{

    std::string Model::GetName()
    {
        return this->m_Name;
    }
    void Model::SetName(std::string value)
    {
        this->m_Name = value;
    }

    bool Model::IsVisible()
    {
        return this->m_IsVisible;
    }
    void Model::SetVisibility(bool value)
    {
        this->m_IsVisible = value;
    }


    void Model::Transform(Transformation::Transformation& transformation)
    {
        boost::numeric::ublas::matrix<ModelDataType> matrix =
            transformation.GetMatrix();
        for (auto it : this->Vectors())
        {
            boost::numeric::ublas::axpy_prod(matrix, it, it, true);
        }	
    }

    void Model::Translate(Transformation::Translation translation)
    {
        boost::numeric::ublas::vector<ModelDataType> translationvec =
            translation.GetTranslation();
        // It's more performant to directly add the vertices together instead of
        // calling the Transform() function and creating a matrix for it.
        for (auto it : this->Vectors())
        {
            it += translationvec;
        }
    }

    void Model::Scale(const ModelDataType factor)
    {
        // And again it's more performant not to use matrices.
        for (auto it : this->Vectors())
        {
            it *= factor;
        }
    }


    void Model::Scale(Transformation::Scale scale)
    {
        boost::numeric::ublas::vector<ModelDataType> scalevec =
            scale.GetScale();
        for (auto it : this->Vectors())
        {
            it = boost::numeric::ublas::element_prod(it, scalevec);
        }
    }


    void Model::Rotate(Transformation::Rotation rotation)
    {
        this->Transform(rotation);
    }


    



    boost::numeric::ublas::matrix<ModelDataType> Model::CreateRotation(
        const boost::numeric::ublas::vector<ModelDataType> planar1,
        const boost::numeric::ublas::vector<ModelDataType> planar2,
        const boost::numeric::ublas::vector<ModelDataType> offset,
        const float angle)
    {
        // TODO Implement Model::CreateRotation.
    }

}
