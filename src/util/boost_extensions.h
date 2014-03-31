// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_BOOST_EXTENSIONS_H
#define CE3D_UTIL_BOOST_EXTENSIONS_H

#include <boost/numeric/ublas/matrix.hpp>

namespace boost
{
namespace numeric
{
namespace ublas
{

template<class T>
bool
invert(matrix<T> const& input, matrix<T>& inverse);

}
}
}

#include "util/boost_extensions_code.h"

#endif /* CE3D_UTIL_BOOST_EXTENSIONS_H */
