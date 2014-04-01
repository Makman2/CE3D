// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_BOOST_EXTENSIONS_H
#define CE3D_UTIL_BOOST_EXTENSIONS_H

namespace boost
{
namespace numeric
{
namespace ublas
{

/**
 * Inverts a given matrix.
 *
 * @param input: The matrix to invert.
 * @param inverse: A reference to a matrix where the result should be stored.
 * @return true on success, false on fail
 * (for example if the matrix is linearly dependent).
 */
template<typename T>
bool
invert(matrix<T> const& input, matrix<T>& inverse);


/**
 * Concats vectors together to a matrix.
 *
 * @param vectors: An array that contains the vectors that should be concatenated.
 * @param count: The number of elements in the array.
 * @return The concatenated matrix.
 */
template<typename T>
matrix<T>
concat_vectors(vector<T> const * const vectors, size_t count);

/**
 * Concats vectors together to a matrix.
 *
 * @param vectors: The std::vector list that contains the vectors to concat.
 * @return The concatenated matrix.
 */
template<typename T>
matrix<T>
concat_vectors(std::vector<vector<T>> const& vectors);

}
}
}

#include "util/boost_extensions_code.h"

#endif /* CE3D_UTIL_BOOST_EXTENSIONS_H */
