// This file is part of CE3D. License: GPL3

#include "transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{


Transformation::Transformation()
: m_Matrix()
, m_needUpdate(false)
{}

Matrix const& Transformation::GetMatrix() const
{
    if (m_needUpdate)
    {
        UpdateMatrix();
        m_needUpdate = false;
    }

    return m_Matrix;
}

}
}
