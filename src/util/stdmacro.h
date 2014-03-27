// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_STDMACRO_H
#define CE3D_UTIL_STDMACRO_H

#include <cstdint>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include "CE3D_config.h"

namespace CE3D
{

/**
 * Data type for model vectors.
 */
using ModelDataType = float;
/**
 * Index type for model vectors.
 */
using ModelIdxType = std::uint32_t;

/**
 * The vector type used for models etc.
 */
using Vector = boost::numeric::ublas::vector<ModelDataType>;

/**
 * The matrix type used for transformations etc.
 */
using Matrix = boost::numeric::ublas::matrix<ModelDataType>;

}

#endif /* CE3D_UTIL_STDMACRO_H */
