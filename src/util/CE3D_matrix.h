// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_MATRIX_H
#define CE3D_UTIL_MATRIX_H

#include "util/stdinc.h"
#include <boost/numeric/ublas/matrix.hpp>

namespace CE3D
{

/**
 * The matrix type used for transformations etc.
 */
using Matrix = boost::numeric::ublas::matrix<ModelDataType>;

}

#endif /* CE3D_UTIL_MATRIX_H */
