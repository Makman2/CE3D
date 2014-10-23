// This file is part of CE3D. License: GPL3

#ifndef CE3D_TEST_TESTUTILITIES_H
#define CE3D_TEST_TESTUTILITIES_H

#include "CE3D/util/CE3D_matrix.h"
#include "CE3D/util/CE3D_vector.h"

namespace CE3D
{
namespace Testing
{

/**
 * Checks if the given matrices are equal.
 *
 * @param a The first matrix.
 * @param b The second matrix.
 * @returns true if both are equal, false if not.
 */
bool IsMatrixEqual(CE3D::Matrix const& a, CE3D::Matrix const& b);

/**
 * Checks if the given matrices are nearly equal.
 *
 * @param a The first matrix.
 * @param b The second matrix.
 * @param tolerance The relative tolerance the matrix-values are allowed to
 * differ.
 * @returns true if both are nearly equal, false if not.
 */
bool IsMatrixEqual(CE3D::Matrix const&       a,
                   CE3D::Matrix const&       b,
                   CE3D::ModelDataType const tolerance);

/**
 * Checks if the given vectors are equal.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @returns true if both are equal, false if not.
 */
bool IsVectorEqual(CE3D::Vector const& a, CE3D::Vector const& b);

/**
 * Checks if the given vectors are nearly equal.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @param tolerance The relative tolerance the vector-values are allowed to
 * differ.
 * @returns true if both are equal, false if not.
 */
bool IsVectorEqual(CE3D::Vector const&       a,
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
CE3D::Matrix RandomMatrix(CE3D::Matrix::size_type m,
                          CE3D::Matrix::size_type n,
                          unsigned int            seed);

/**
 * Creates a matrix with randomized values. The initial seed is calculated from
 * time when function executes.
 *
 * @param m    The row dimension of the new matrix.
 * @param n    The column dimension of the new matrix.
 */
CE3D::Matrix RandomMatrix(CE3D::Matrix::size_type m,
                          CE3D::Matrix::size_type n);
}
}

#endif /* CE3D_TEST_TESTUTILITIES_H */
