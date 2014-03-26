// This file is part of CE3D. License: GPL3

#include "transformation/scale.h"

namespace CE3D
{
namespace Transformation
{

void Scale::SetScale(
    boost::numeric::ublas::vector<ModelDataType> value)
{
    m_Matrix.resize(value.size(), value.size());

    for (boost::numeric::ublas::matrix<ModelDataType>::size_type row = 0;
         row < m_Matrix.size1(); row++)
    {
        for (boost::numeric::ublas::matrix<ModelDataType>::size_type column = 0;
            column < m_Matrix.size2(); column++)
        {
            if (row == column)
                m_Matrix(row, column) = value(row);
            else
                m_Matrix(row, column) = 0.0f;
        }
    }

    m_Scale = value;
}

boost::numeric::ublas::vector<ModelDataType> Scale::GetScale() const
{
    return m_Scale;
}

}
}
