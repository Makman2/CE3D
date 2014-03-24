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


    void Model::Transform(boost::numeric::ublas::matrix<ModelDataType> matrix)
    {
        for (auto it : this->Vectors())
        {
            boost::numeric::ublas::axpy_prod(matrix, it, it, true);
        }	
    }

    void Model::Translate(boost::numeric::ublas::vector<ModelDataType> translation)
    {
        // It's more performant to directly add the vertices together instead of
        // calling the Transform() function and creating a matrix for it.
        for (auto it : this->Vectors())
        {
            it += translation;
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

    void Model::Scale(const boost::numeric::ublas::vector<ModelDataType> scale)
    {
        for (auto it : this->Vectors())
        {
            it = boost::numeric::ublas::element_prod(it, scale);
        }
    }

    void Model::Rotate(const boost::numeric::ublas::vector<ModelDataType> planar1,
        const boost::numeric::ublas::vector<ModelDataType> planar2, 
    const boost::numeric::ublas::vector<ModelDataType> offset, const float angle)
    {
        this->Transform(CreateRotation(planar1, planar2, offset, angle));
    }

    boost::numeric::ublas::matrix<ModelDataType> Model::CreateTranslation(
        boost::numeric::ublas::vector<ModelDataType> translation)
    {
        boost::numeric::ublas::matrix<ModelDataType> matrix(
            translation.size() + 1, translation.size() + 1);
        
        for (boost::numeric::ublas::matrix<ModelDataType>::size_type row = 0;
             row < matrix.size1(); row++)
        {
            boost::numeric::ublas::matrix<ModelDataType>::size_type column;
             
            for (column = 0; column < matrix.size2() - 1; column++)
            {
                if (row == column)
                    matrix(row, column) = 1.0f;
                else
                    matrix(row, column) = 0.0f;
            }
            
            column++;
            if (row == matrix.size1() - 1)
                matrix(row, column) = 1.0f;
            else
                matrix(row, column) = translation(row);
        }

        return matrix;
    }


    boost::numeric::ublas::matrix<ModelDataType> Model::CreateScale(
        const boost::numeric::ublas::vector<ModelDataType> scale)
    {
        boost::numeric::ublas::matrix<ModelDataType> matrix(
            scale.size(), scale.size());            
        
        for (boost::numeric::ublas::matrix<ModelDataType>::size_type row = 0;
             row < matrix.size1(); row++)
        {
            for (boost::numeric::ublas::matrix<ModelDataType>::size_type column = 0;
                column < matrix.size2(); column++)
            {
                if (row == column)
                    matrix(row, column) = scale(row);
                else
                    matrix(row, column) = 0.0f;
            }
        }

        return matrix;
    }

    boost::numeric::ublas::matrix<ModelDataType> Model::CreateScale(
    const ModelDataType factor,
    const boost::numeric::ublas::vector<ModelDataType>::size_type dimension)
    {
        boost::numeric::ublas::matrix<ModelDataType> matrix(dimension, dimension);            
        
        for (boost::numeric::ublas::matrix<ModelDataType>::size_type row = 0;
             row < matrix.size1(); row++)
        {
            for (boost::numeric::ublas::matrix<ModelDataType>::size_type column = 0;
                column < matrix.size2(); column++)
            {
                if (row == column)
                    matrix(row, column) = factor;
                else
                    matrix(row, column) = 0.0f;
            }
        }

        return matrix;
    }



    boost::numeric::ublas::matrix<ModelDataType> Model::CreateRotation(
        const boost::numeric::ublas::vector<ModelDataType> planar1,
        const boost::numeric::ublas::vector<ModelDataType> planar2,
        const boost::numeric::ublas::vector<ModelDataType> offset, const float angle)
    {
        // TODO Implement Model::CreateRotation.
    }

}
