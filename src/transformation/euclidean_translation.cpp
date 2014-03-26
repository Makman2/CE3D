// This file is part of CE3D. License: GPL3

#include "transformation/euclidean_translation.h"

namespace CE3D
{
namespace Transformation
{

    void EuclideanTranslation::SetTranslation(
        boost::numeric::ublas::vector<ModelDataType> value)
    {
        m_Matrix.resize(value.size(), value.size());
        
        boost::numeric::ublas::matrix<ModelDataType> matrix(
            value.size() + 1, value.size() + 1);
        
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
                matrix(row, column) = value(row);
        }

        m_TranslationVector = value;
    }

    boost::numeric::ublas::vector<ModelDataType>
        EuclideanTranslation::GetTranslation() const
    {
        return m_TranslationVector;
    }
    
    boost::numeric::ublas::matrix<ModelDataType> 
        EuclideanTranslation::GetMatrix() const
    {
        return m_Matrix;
    }

}
}
