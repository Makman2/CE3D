// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_CE3D_MATRIX_H
#define CE3D_UTIL_CE3D_MATRIX_H

#include "CE3D/util/stdinc.h"
#include <boost/numeric/ublas/matrix.hpp>

namespace CE3D
{

/**
 * The matrix type used for transformations etc.
 */
using Matrix = boost::numeric::ublas::matrix<ModelDataType>;
using IdentityMatrix = boost::numeric::ublas::identity_matrix<ModelDataType>;
using ZeroMatrix = boost::numeric::ublas::zero_matrix<ModelDataType>;

}

#endif /* CE3D_UTIL_CE3D_MATRIX_H */
