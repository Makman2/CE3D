// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE BoostExtensions
#include <boost/test/unit_test.hpp>

#include "CE3D/util/stdinc.h"

#include "CE3D/util/CE3D_matrix.h"
#include "CE3D/test/transformation/transformation_test.h"
#include "CE3D/util/boost_extensions.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(Util, TestEnvironment)

/**
 * Tests the invert method.
 */
BOOST_AUTO_TEST_CASE(TestInverseCalculation)
{
    CE3D::Matrix identity =
        boost::numeric::ublas::identity_matrix<ModelDataType>(4, 4);
    CE3D::Matrix inversion(4,4);

    boost::numeric::ublas::invert(identity, inversion);

    RequireMatrixEquality(identity, inversion);

    // TODO test what invert does with wrong dimensions
}

// TODO test vector concatenation

BOOST_AUTO_TEST_SUITE_END()

}
}
