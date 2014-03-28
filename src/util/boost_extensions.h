// This file is part of CE3D. License: GPL3

#include <boost/numeric/ublas/matrix.hpp>

#include "util/stdmacro.h"

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
