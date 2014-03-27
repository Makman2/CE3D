// This file is part of CE3D. License: GPL3

#include "transformation/scale.h"

namespace CE3D
{
namespace Transformation
{
    void Scale::UpdateMatrix()
    {
        m_Matrix.resize(m_Scale.size(), m_Scale.size());

        for (boost::numeric::ublas::matrix<ModelDataType>::size_type row = 0;
             row < m_Matrix.size1(); row++)
        {
            for (boost::numeric::ublas::matrix<ModelDataType>::size_type column = 0;
                column < m_Matrix.size2(); column++)
            {
                if (row == column)
                    m_Matrix(row, column) = m_Scale(row);
                else
                    m_Matrix(row, column) = 0.0f;
            }
        }
    }

    void Scale::SetScale(
        boost::numeric::ublas::vector<ModelDataType> const& scale)
    {
        m_Scale = scale;
        UpdateMatrix();
    }

}
}
