// This file is part of CE3D. License: GPL3

#include "transformation/translation.h"

namespace CE3D
{
namespace Transformation
{

void Translation::UpdateMatrix()
{
    m_Matrix.resize(
        m_TranslationVector.size() + 1, m_TranslationVector.size() + 1);
            
    for (boost::numeric::ublas::matrix<ModelDataType>::size_type row = 0;
         row < m_Matrix.size1(); row++)
    {
        boost::numeric::ublas::matrix<ModelDataType>::size_type column;
        
        for (column = 0; column < m_Matrix.size2() - 1; column++)
        {
            if (row == column)
                m_Matrix(row, column) = 1.0f;
            else
                m_Matrix(row, column) = 0.0f;
        }
        
        column++;
        if (row == m_Matrix.size1() - 1)
            m_Matrix(row, column) = 1.0f;
        else
            m_Matrix(row, column) = m_TranslationVector(row);
    }
}


void Translation::SetTranslation(
    boost::numeric::ublas::vector<ModelDataType> const& shift)
{
    m_TranslationVector = shift;
    UpdateMatrix();
}

void Translation::SetTranslation(
    boost::numeric::ublas::vector<ModelDataType> const& direction,
    ModelDataType const length)
{
    ModelDataType norm = boost::numeric::ublas::norm_2(direction);
    m_TranslationVector = (direction / norm) * length;
    UpdateMatrix();        
}

}
}
