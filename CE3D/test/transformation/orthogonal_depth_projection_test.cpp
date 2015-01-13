// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OrthogonalDepthProjection
#include <boost/test/unit_test.hpp>

#include "CE3D/util/stdinc.h"

#include "CE3D/test/testutilities.h"
#include "CE3D/transformation/orthogonal_depth_projection.h"


namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(OrthogonalDepthProjection, TestEnvironment)

/**
 * Tests the construction and destruction of OrthogonalDepthProjection.
 */
BOOST_AUTO_TEST_CASE(TestOrthogonalDepthProjectionConstruction)
{
    std::shared_ptr<CE3D::Transformation::OrthogonalDepthProjection> TestUnit;

    // Parameterless constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Transformation::OrthogonalDepthProjection()));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());

    // Copy constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Transformation::OrthogonalDepthProjection(
        CE3D::Transformation::OrthogonalDepthProjection())));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());

    // (Vector) constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Transformation::OrthogonalDepthProjection(
        CE3D::Vector())));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());

    // (std::vector<Vector>) constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Transformation::OrthogonalDepthProjection(
        std::vector<CE3D::Vector>(3))));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());
}

BOOST_AUTO_TEST_SUITE_END()

}
}
