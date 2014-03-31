// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_BOOST_EXTENSIONS_CODE_H
#define CE3D_UTIL_BOOST_EXTENSIONS_CODE_H

#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>

#include "util/boost_extensions.h"

namespace boost
{
namespace numeric
{
namespace ublas
{

template<class T>
bool invert(matrix<T> const& input, matrix<T>& inverse)
{
    // create a working copy of the input
    matrix<T> A(input);

    // create a permutation matrix for the LU-factorization
    permutation_matrix<std::size_t> pm(A.size1());

    // perform LU-factorization
    int res = lu_factorize(A, pm);
    if (res != 0)
        return false;

    // create identity matrix of "inverse"
    inverse.assign(identity_matrix<T> (A.size1()));

    // backsubstitute to get the inverse
    lu_substitute(A, pm, inverse);

    return true;
}


}
}
}

#endif /* CE3D_UTIL_BOOST_EXTENSIONS_CODE_H */
