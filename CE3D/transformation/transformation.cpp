// This file is part of CE3D. License: GPL3

#include "CE3D/transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{

Transformation::Transformation()
: m_Matrix()
, m_NeedUpdate(true)
{}

Transformation::~Transformation()
{}

Matrix const& Transformation::GetMatrix() const
{
    if (m_NeedUpdate)
    {
        UpdateMatrix();
        m_NeedUpdate = false;
    }

    return m_Matrix;
}

}
}
