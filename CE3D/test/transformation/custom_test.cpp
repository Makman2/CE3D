// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OrthogonalProjection
#include <boost/test/unit_test.hpp>

#include "CE3D/util/stdinc.h"

#include "CE3D/test/testutilities.h"
#include "CE3D/transformation/custom.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(Custom, TestEnvironment)

/**
 * Tests the construction and destruction of Custom.
 */
BOOST_AUTO_TEST_CASE(TestCustomConstruction)
{
    CE3D::Transformation::Custom *TestUnit;
    BOOST_REQUIRE_NO_THROW(TestUnit = new CE3D::Transformation::Custom());
    BOOST_REQUIRE_NO_THROW(delete TestUnit);
}

BOOST_AUTO_TEST_CASE(TestCustomMatrixConstruction)
{
    CE3D::Transformation::Custom *TestUnit;
    CE3D::Matrix TestMatrix = CE3D::IdentityMatrix(4,4);
    TestMatrix(2,3) = 4;
    BOOST_REQUIRE_NO_THROW(TestUnit =
                           new CE3D::Transformation::Custom(TestMatrix));

    BOOST_CHECK(IsMatrixEqual(TestMatrix, TestUnit->GetMatrix()));

    BOOST_REQUIRE_NO_THROW(delete TestUnit);
}

BOOST_AUTO_TEST_CASE(TestCustomGetSet)
{
    CE3D::Transformation::Custom TestUnit;


    CE3D::Matrix TestMatrix = CE3D::IdentityMatrix(4,4);
    TestMatrix(2,3) = 4;
    TestUnit.SetMatrix(TestMatrix);
    BOOST_CHECK(IsMatrixEqual(TestMatrix, TestUnit.GetMatrix()));
}

BOOST_AUTO_TEST_CASE(TestCustomAppend)
{
    CE3D::Transformation::Custom TestUnit;

    CE3D::Matrix TestMatrix = CE3D::IdentityMatrix(4,4);

    TestUnit.SetMatrix(TestMatrix);
    TestUnit.AppendTransformation(TestUnit);

    BOOST_CHECK(IsMatrixEqual(TestMatrix, TestUnit.GetMatrix()));
}

BOOST_AUTO_TEST_SUITE_END()

}
}
