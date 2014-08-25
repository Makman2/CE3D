// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OrthogonalProjection
#include <boost/test/unit_test.hpp>

#include "CE3D/util/stdinc.h"

#include "CE3D/test/testutilities.h"
#include "CE3D/util/boost_extensions.h"
#include "CE3D/transformation/orthogonal_projection.h"


namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(OrthogonalProjection, TestEnvironment)

/**
 * Tests the construction and destruction of OrthogonalProjection.
 */
BOOST_AUTO_TEST_CASE(TestOrthogonalProjectionConstruction)
{
    CE3D::Transformation::OrthogonalProjection *TestUnit;
    BOOST_REQUIRE_NO_THROW(TestUnit =
        new CE3D::Transformation::OrthogonalProjection());
    BOOST_REQUIRE_NO_THROW(delete TestUnit);
}

/**
 * Tests the matrix generation of OrthogonalProjection.
 */
BOOST_AUTO_TEST_CASE(TestOrthogonalProjectionGetSet)
{
    // First matrix test.

    BOOST_TEST_MESSAGE("Testing 3x3 orthogonal projection matrix...");

    CE3D::Transformation::OrthogonalProjection TestUnit;

    std::vector<CE3D::Vector> span;
    CE3D::Vector span1(3);
    span1[0] = 2.0f;
    span1[1] = 0.0f;
    span1[2] = 0.0f;
    CE3D::Vector span2(3);
    span2[0] = 0.0f;
    span2[1] = 0.0f;
    span2[2] = 1.0f;

    span.push_back(span1);
    span.push_back(span2);

    BOOST_TEST_MESSAGE("Setting projection vectors...");

    TestUnit.SetProjectionVectors(span);

    BOOST_TEST_MESSAGE("Testing matrix...");

    CE3D::Matrix Comparison = CE3D::Matrix(2, 3);
    Comparison(0, 0) = 0.5f;
    Comparison(0, 1) = 0.0f;
    Comparison(0, 2) = 0.0f;
    Comparison(1, 0) = 0.0f;
    Comparison(1, 1) = 0.0f;
    Comparison(1, 2) = 1.0f;

    BOOST_CHECK(IsMatrixEqual(Comparison, TestUnit.GetMatrix()));

    span.clear();

    BOOST_TEST_MESSAGE("Testing 3x3 orthogonal projection matrix...");
    // Second matrix test.

    span1.resize(4, false);
    span1[0] = 1;
    span1[1] = 1;
    span1[2] = 1;
    span1[3] = 1;

    span2.resize(4, false);
    span2[0] = 2;
    span2[1] = 2;
    span2[2] = 3;
    span2[3] = 3;

    CE3D::Vector span3(4);
    span3[0] = 3;
    span3[1] = 3;
    span3[2] = 4;
    span3[3] = 2;

    span.push_back(span1);
    span.push_back(span2);
    span.push_back(span3);

    BOOST_TEST_MESSAGE("Setting projection vectors...");

    TestUnit.SetProjectionVectors(span);

    BOOST_TEST_MESSAGE("Testing matrix...");

    Comparison.resize(3, 4);
    Comparison(0, 0) = 1.5f;
    Comparison(0, 1) = 1.5f;
    Comparison(0, 2) = -2.5f;
    Comparison(0, 3) = 0.5f;
    Comparison(1, 0) = -0.5f;
    Comparison(1, 1) = -0.5f;
    Comparison(1, 2) = 0.5f;
    Comparison(1, 3) = 0.5f;
    Comparison(2, 0) = 0.0f;
    Comparison(2, 1) = 0.0f;
    Comparison(2, 2) = 0.5f;
    Comparison(2, 3) = -0.5f;

    auto nullified_matrix = TestUnit.GetMatrix();
    boost::numeric::ublas::make_zero(nullified_matrix, 0.000001);
    BOOST_CHECK(IsMatrixEqual(Comparison, nullified_matrix, 0.001));
}

BOOST_AUTO_TEST_SUITE_END()

}
}
