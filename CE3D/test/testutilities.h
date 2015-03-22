// This file is part of CE3D. License: GPL3

#ifndef CE3D_TEST_TESTUTILITIES_H
#define CE3D_TEST_TESTUTILITIES_H

#include <boost/date_time.hpp>

#include "CE3D/util/CE3D_matrix.h"
#include "CE3D/util/CE3D_vector.h"

namespace CE3D
{
namespace Testing
{

/**
 * Gets the time since epoch (1.1.1970).
 *
 * @returns The time since epoch in seconds.
 */
boost::date_time::time_duration
<boost::posix_time::time_duration, boost::posix_time::time_res_traits>::
sec_type
SecondsSinceEpoch();

/**
 * Gets the time since epoch (1.1.1970).
 *
 * @returns The time since epoch in nanoseconds.
 */
boost::date_time::time_duration
<boost::posix_time::time_duration, boost::posix_time::time_res_traits>::
tick_type
NanosecondsSinceEpoch();

/**
 * Checks if the given matrices are equal.
 *
 * @param a The first matrix.
 * @param b The second matrix.
 * @returns true if both are equal, false if not.
 */
bool
IsMatrixEqual(CE3D::Matrix const& a, CE3D::Matrix const& b);

/**
 * Checks if the given matrices are nearly equal. Tests for relative equality.
 *
 * @param a The first matrix.
 * @param b The second matrix.
 * @param tolerance The relative tolerance the matrix-values are allowed to
 * differ.
 * @returns true if both are nearly equal, false if not.
 */
bool
IsMatrixEqual(CE3D::Matrix const&       a,
              CE3D::Matrix const&       b,
              CE3D::ModelDataType const tolerance);

/**
 * Checks if the given vectors are equal.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @returns true if both are equal, false if not.
 */
bool
IsVectorEqual(CE3D::Vector const& a, CE3D::Vector const& b);

/**
 * Checks if the given vectors are nearly equal. Tests for relative equality.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @param tolerance The relative tolerance the vector-values are allowed to
 * differ.
 * @returns true if both are equal, false if not.
 */
bool
IsVectorEqual(CE3D::Vector const&       a,
              CE3D::Vector const&       b,
              CE3D::ModelDataType const tolerance);

/**
 * Creates a matrix with randomized values.
 *
 * @param m    The row dimension of the new matrix.
 * @param n    The column dimension of the new matrix.
 * @param seed A random number to use as starting value
 *             randomizer-initialization.
 */
CE3D::Matrix
RandomMatrix(CE3D::Matrix::size_type m,
             CE3D::Matrix::size_type n,
             unsigned int            seed);

/**
 * Creates a matrix with randomized values. The initial seed is calculated from
 * time when function executes.
 *
 * @param m    The row dimension of the new matrix.
 * @param n    The column dimension of the new matrix.
 */
CE3D::Matrix
RandomMatrix(CE3D::Matrix::size_type m, CE3D::Matrix::size_type n);

/**
* Generates a random value.
*
* @param seed Any value from that random value is calculated.
* @returns Random value.
*/
float
Random(unsigned int seed);

/**
 * Generates a random value. The initial seed is calculated from time when
 * function executes.
 *
 * @returns Random value.
 */
float
Random();

/**
 * Generates a vector filled with random values.
 *
 * @param count The size of the vector.
 * @param seed  The random generator initialization value.
 * @returns     A vector filled with random values.
 */
std::vector<float>
RandomVector(std::vector<float>::size_type count, unsigned int seed);

/**
* Generates a vector filled with random values. The seed is calculated from
* the current time.
*
* @param count The size of the vector.
* @returns     A vector filled with random values.
*/
std::vector<float>
RandomVector(std::vector<float>::size_type count);

}
}

#endif /* CE3D_TEST_TESTUTILITIES_H */
