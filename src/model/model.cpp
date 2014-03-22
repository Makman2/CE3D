// This file is part of CE3D. License: GPL3

#include "model.h"

#include <boost/numeric/ublas/operation_blocked.hpp>
#include <boost/numeric/ublas/operation.hpp>

namespace CE3D
{
// TODO: Doxygen comments.
void Model::Transform(boost::numeric::ublas::matrix<ModelDataType> matrix)
{
    for (boost::container::vector<ModelDataType>::size_type
        i = Vectors().begin(); i != Vectors().end(); i++)
    {
        boost::numeric::ublas::axpy_prod(matrix, Vectors().at(i),
                                         Vectors().at(i), true);
    }
}

}
