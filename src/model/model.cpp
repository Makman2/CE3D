// This file is part of CE3D. License: GPL3

#include "model.h"

#include <boost/numeric/ublas/operation_blocked.hpp>
#include <boost/numeric/ublas/operation.hpp>

namespace CE3D
{

void Model::Transform(boost::numeric::ublas::matrix<ModelDataType> matrix)
{
    for (auto& it : m_Vectors)
    {
        boost::numeric::ublas::axpy_prod(matrix, it, it, true);
    }
}

}
