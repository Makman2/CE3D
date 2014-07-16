// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_BOOST_EXTENSIONS_CODE_H
#define CE3D_UTIL_BOOST_EXTENSIONS_CODE_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace boost
{
namespace numeric
{
namespace ublas
{

template<typename T>
bool
invert(matrix<T> const& input, matrix<T>& inverse)
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

template<typename T>
matrix<T>
concat_vectors(vector<T> const * const vectors, size_t count)
{
    // Check bounds.
    for (size_t i = 1; i < count; i++)
    {
        if (vectors[i - 1].size() != vectors[i].size())
            throw std::invalid_argument
                ("Vectors doesn't have the same length.");
    }

    matrix<T> M((*vectors).size(), count);
    for (typename matrix<T>::size_type column = 0; column < M.size2();
         column++)
    {
        for (typename matrix<T>::size_type row = 0; row < M.size1(); row++)
        {
            M(row, column) = vectors[column](row);
        }
    }

    return M;
}

template<typename T>
matrix<T>
concat_vectors(std::vector<vector<T>> const& vectors)
{
    // Check bounds.
    for (typename std::vector<T>::size_type i = 1; i < vectors.size(); i++)
    {
        if (vectors.at(i - 1).size() != vectors.at(i).size())
            throw std::invalid_argument
                ("Vectors doesn't have the same length.");
    }
    
    matrix<T> M(vectors.at(0).size(), vectors.size());
    for (typename matrix<T>::size_type column = 0; column < M.size2();
         column++)
    {
        for (typename matrix<T>::size_type row = 0; row < M.size1(); row++)
        {
            M(row, column) = vectors.at(column)(row);
        }
    }

    return M;
}

}
}
}

#endif /* CE3D_UTIL_BOOST_EXTENSIONS_CODE_H */
