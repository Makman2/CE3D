// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE BoostExtensions
#include <boost/test/unit_test.hpp>

#include "util/stdinc.h"

#include "util/CE3D_matrix.h"
#include "test/transformation/transformation_test.h"
#include "util/boost_extensions.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(Util, TestEnvironment)

/**
 * Tests the construction and destruction of Translation.
 */
BOOST_AUTO_TEST_CASE(TestInverseCalculation)
{
    CE3D::Matrix identity = boost::numeric::ublas::identity_matrix<ModelDataType>(4, 4);
    CE3D::Matrix inversion(4,4);

    boost::numeric::ublas::invert(identity, inversion);

    RequireMatrixEquality(identity, inversion);

    // TODO test what invert does with wrong dimensions
}

BOOST_AUTO_TEST_SUITE_END()

}
}
