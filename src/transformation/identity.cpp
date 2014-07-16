// This file is part of CE3D. License: GPL3

#include "transformation/identity.h"

namespace CE3D
{
namespace Transformation
{

Identity::Identity()
: m_dim1()
, m_dim2()
{}

Identity::Identity(Matrix::size_type dim)
: m_dim1(dim)
, m_dim2(dim)
{}

Identity::Identity(Matrix::size_type dim1, Matrix::size_type dim2)
: m_dim1(dim1)
, m_dim2(dim2)
{}

void Identity::UpdateMatrix() const
{
    m_Matrix = boost::numeric::ublas::identity_matrix<Matrix::value_type>
        (m_dim1, m_dim2);
}

Matrix::size_type const& Identity::GetDimension1() const
{
    return m_dim1;
}

void Identity::SetDimension1(Matrix::size_type value)
{
    m_NeedUpdate = true;
    m_dim1 = value;
}

Matrix::size_type const& Identity::GetDimension2() const
{
    return m_dim2;
}

void Identity::SetDimension2(Matrix::size_type value)
{
    m_NeedUpdate = true;
    m_dim2 = value;
}

}
}
