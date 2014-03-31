// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OrthogonalProjection
#include <boost/test/unit_test.hpp>

#include "util/stdinc.h"

#include "util/CE3D_matrix.h"
#include "test/transformation/transformation_test.h"
#include "transformation/orthogonal_projection.h"

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
 * Tests the construction and destruction of OrthogonalProjection.
 */
BOOST_AUTO_TEST_CASE(TestOrthogonalProjectionGetSet)
{
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

    TestUnit.SetProjectionVectors(span);

    CE3D::Matrix Comparision =
        boost::numeric::ublas::matrix<ModelDataType>(2, 3);
    Comparision(0, 0) = 0.5f;
    Comparision(0, 1) = 0.0f;
    Comparision(0, 2) = 0.0f;
    Comparision(1, 0) = 0.0f;
    Comparision(1, 1) = 0.0f;
    Comparision(1, 2) = 1.0f;

    RequireMatrixEquality(Comparision, TestUnit.GetMatrix());

}

BOOST_AUTO_TEST_SUITE_END()

}
}
