// This file is part of CE3D. License: GPL3

#include "transformation/scale.h"

namespace CE3D
{
namespace Transformation
{
    void Scale::UpdateMatrix()
    {
        m_Matrix.resize(m_Scale.size(), m_Scale.size());

        for (Matrix::size_type row = 0; row < m_Matrix.size1(); row++)
        {
            for (Matrix::size_type column = 0; column < m_Matrix.size2(); column++)
            {
                if (row == column)
                    m_Matrix(row, column) = m_Scale(row);
                else
                    m_Matrix(row, column) = 0.0f;
            }
        }
    }

    void Scale::SetScale(Vector const& scale)
    {
        m_Scale = scale;
        
        m_needUpdate = true;
    }

}
}
