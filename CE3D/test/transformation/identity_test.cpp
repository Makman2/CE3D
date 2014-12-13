// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Identity
#include <boost/test/unit_test.hpp>

#include "CE3D/util/stdinc.h"

#include "CE3D/test/testutilities.h"
#include "CE3D/transformation/identity.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(Identity, TestEnvironment)

/**
 * Tests the construction and destruction of Identity.
 */
BOOST_AUTO_TEST_CASE(TestIdentityConstruction)
{
    std::shared_ptr<CE3D::Transformation::Identity> TestUnit;

    // Parameterless constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Transformation::Identity()));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());

    // Copy constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Transformation::Identity(
        CE3D::Transformation::Identity())));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());

    // (size_type) constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Transformation::Identity(3)));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());

    // (size_type, size_type) constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Transformation::Identity(3, 2)));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());
}

/**
 * Tests the calculated identity matrix.
 */
BOOST_AUTO_TEST_CASE(TestIdentityMatrix)
{
    CE3D::Transformation::Identity TestUnit(3, 3);

    CE3D::IdentityMatrix compare(3, 3);

    BOOST_CHECK(IsMatrixEqual(TestUnit.GetMatrix(), compare));

    CE3D::Transformation::Identity TestUnit2(2, 4);
    CE3D::IdentityMatrix compare2(2, 4);

    BOOST_CHECK(IsMatrixEqual(TestUnit2.GetMatrix(), compare2));
}

BOOST_AUTO_TEST_SUITE_END()

}
}
