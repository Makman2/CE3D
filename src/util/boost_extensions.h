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

/**
 * Concats vectors together to a matrix.
 */
template<class T>
boost::numeric::ublas::matrix<T>
concat_vectors(boost::numeric::ublas::vector<T> const * const vectors, size_t count);

template<class T>
boost::numeric::ublas::matrix<T>
concat_vectors(std::vector<boost::numeric::ublas::vector<T>> vectors);

}
}
}
