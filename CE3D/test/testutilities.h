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
 * Invokes BOOST_REQUIRE_EQUAL for each matrix element.
 */
void RequireMatrixEquality(CE3D::Matrix const& a, CE3D::Matrix const& b);

/**
 * Invokes BOOST_REQUIRE_SMALL for each matrix element.
 */
void RequireMatrixEquality(CE3D::Matrix const&       a,
                           CE3D::Matrix const&       b,
                           CE3D::ModelDataType const tolerance);

/**
 * Invokes BOOST_REQUIRE_EQUAL for each Vector element.
 */
void RequireVectorEquality(CE3D::Vector const& a, CE3D::Vector const& b);

/**
 * Invokes BOOST_REQUIRE_SMALL for each vector element.
 */
void RequireVectorEquality(CE3D::Vector const&       a,
                           CE3D::Vector const&       b,
                           CE3D::ModelDataType const tolerance);

/**
 * Creates a matrix with randomized values.
 */
CE3D::Matrix RandomMatrix
    (CE3D::Matrix::size_type m, CE3D::Matrix::size_type n, unsigned int seed);

}
}

#endif /* CE3D_TEST_TESTUTILITIES_H */
