// This file is part of CE3D. License: GPL3

#ifndef CE3D_TEST_TRANSFORMATION_TRANSFORMATION_TEST_H
#define CE3D_TEST_TRANSFORMATION_TRANSFORMATION_TEST_H

#include "CE3D/util/CE3D_matrix.h"
#include "CE3D/util/CE3D_vector.h"

/**
 * Invokes BOOST_REQUIRE_EQUAL for each matrix element.
 */
void RequireMatrixEquality(CE3D::Matrix const, CE3D::Matrix const);


/**
 * Invokes BOOST_REQUIRE_SMALL for each matrix element.
 */
void RequireMatrixEquality
    (CE3D::Matrix const, CE3D::Matrix const, float tolerance);

/**
 * Invokes BOOST_REQUIRE_EQUAL for each Vector element.
 */
void RequireVectorEquality
    (CE3D::Vector const, CE3D::Vector const);

/**
 * Invokes BOOST_REQUIRE_SMALL for each vector element.
 */
void RequireVectorEquality
    (CE3D::Vector const, CE3D::Vector const, float tolerance);

/**
 * Creates a matrix with randomized values.
 */
CE3D::Matrix RandomMatrix
    (CE3D::Matrix::size_type m, CE3D::Matrix::size_type n, unsigned int seed);


#endif /* CE3D_TEST_TRANSFORMATION_TRANSFORMATION_TEST_H */
