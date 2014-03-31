// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_CE3D_VECTOR_H
#define CE3D_UTIL_CE3D_VECTOR_H

#include "util/stdinc.h"
#include <boost/numeric/ublas/vector.hpp>

namespace CE3D
{

/**
 * The vector type used for models etc.
 */
using Vector = boost::numeric::ublas::vector<ModelDataType>;

}

#endif /* CE3D_UTIL_CE3D_VECTOR_H */
