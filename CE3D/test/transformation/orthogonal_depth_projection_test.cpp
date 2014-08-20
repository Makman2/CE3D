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
    CE3D::Transformation::OrthogonalProjection *TestUnit;
    BOOST_REQUIRE_NO_THROW(TestUnit =
        new CE3D::Transformation::OrthogonalDepthProjection());
    BOOST_REQUIRE_NO_THROW(delete TestUnit);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
