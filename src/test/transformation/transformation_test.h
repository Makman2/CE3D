// This file is part of CE3D. License: GPL3

#ifndef CE3D_TEST_TRANSFORMATION_TRANSFORMATION_TEST_H
#define CE3D_TEST_TRANSFORMATION_TRANSFORMATION_TEST_H

#include "util/stdinc.h"

#include "util/CE3D_matrix.h"
#include "util/CE3D_vector.h"

/**
 * Invokes BOOST_REQUIRE_EQUAL for each matrix element.
 */
void RequireMatrixEquality(CE3D::Matrix const, CE3D::Matrix const);

/**
 * Invokes BOOST_REQUIRE_EQUAL for each Vector element.
 */
void RequireVectorEquality(CE3D::Vector const, CE3D::Vector const);

/**
 * This test method ensures that the intended functionality of any derived
 * object provided by the Transformation base class is available.
 *
 * @param Tester The object under test.
 */
void CE3DTestTransformation();

#endif /* CE3D_TEST_TRANSFORMATION_TRANSFORMATION_TEST_H */
