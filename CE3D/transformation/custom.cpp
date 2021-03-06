// This file is part of CE3D. License: GPL3

#include "CE3D/transformation/custom.h"

#include <boost/numeric/ublas/operation.hpp>

namespace CE3D
{
namespace Transformation
{

Custom::Custom()
{}

Custom::Custom(Matrix const& matrix)
{
    m_Matrix = matrix;
}

void
Custom::UpdateMatrix() const
{}

Custom::~Custom()
{}

void
Custom::AppendTransformation(Transformation const& Trafo)
{
    Matrix const& TrafoMatrix = Trafo.GetMatrix();
    if (TrafoMatrix.size2() != m_Matrix.size1())
    {
        throw std::invalid_argument("Matrix bounds do not match.");
    }

    Matrix Result(m_Matrix.size1(), TrafoMatrix.size2());
    boost::numeric::ublas::axpy_prod(m_Matrix, TrafoMatrix, Result, true);
    m_Matrix = std::move(Result);
}

void
Custom::SetMatrix(Matrix const& value)
{
    m_Matrix = value;
}

}
}
