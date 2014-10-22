// This file is part of CE3D. License: GPL3

#include "CE3D/transformation/scale.h"

namespace CE3D
{
namespace Transformation
{


Scale::Scale()
: m_Scale()
{}

Scale::Scale(Vector const& scale)
: m_Scale(scale)
{}

Scale::~Scale()
{}

void Scale::UpdateMatrix() const
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

Vector const&
Scale::GetScale() const
{
    return m_Scale;
}

void Scale::SetScale(Vector const& scale)
{
    m_Scale = scale;

    m_NeedUpdate = true;
}


}
}
