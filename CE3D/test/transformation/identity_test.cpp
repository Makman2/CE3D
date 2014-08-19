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
 * Tests the construction and destruction of Translation.
 */
BOOST_AUTO_TEST_CASE(TestIdentityConstruction)
{
    CE3D::Transformation::Identity *TestUnit;
    BOOST_REQUIRE_NO_THROW(TestUnit = new CE3D::Transformation::Identity());
    BOOST_REQUIRE_NO_THROW(delete TestUnit);
}

/**
 * Tests the construction and destruction of Translation.
 */
BOOST_AUTO_TEST_CASE(TestIdentityMatrix)
{
    CE3D::Transformation::Identity TestUnit(3, 3);

    boost::numeric::ublas::identity_matrix<Matrix::value_type> compare(3, 3);

    RequireMatrixEquality(TestUnit.GetMatrix(), compare);

    CE3D::Transformation::Identity TestUnit2(2, 4);
    boost::numeric::ublas::identity_matrix<Matrix::value_type> compare2(2, 4);

    RequireMatrixEquality(TestUnit2.GetMatrix(), compare2);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
