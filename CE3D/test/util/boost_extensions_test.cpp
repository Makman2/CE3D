// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE BoostExtensions
#include <boost/test/unit_test.hpp>

#include "CE3D/util/stdinc.h"

#include "CE3D/test/testutilities.h"

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

/**
 * Tests the orthogonalize functions.
 */
BOOST_AUTO_TEST_CASE(TestOrthogonalize)
{
    // Test for already orthogonal vectors.
    std::vector<CE3D::Vector> base;
    CE3D::Vector tmp(4);

    tmp(0) = 1;
    tmp(1) = 0;
    tmp(2) = 0;
    tmp(3) = 0;
    base.push_back(tmp);

    tmp(0) = 0;
    tmp(1) = 1;
    tmp(2) = 0;
    tmp(3) = 0;
    base.push_back(tmp);

    tmp(0) = 0;
    tmp(1) = 0;
    tmp(2) = 1;
    tmp(3) = 0;
    base.push_back(tmp);

    tmp(0) = 0;
    tmp(1) = 0;
    tmp(2) = 0;
    tmp(3) = 1;
    base.push_back(tmp);

    auto testvec = boost::numeric::ublas::orthogonalize(base);
    
    // The vectors should be equal because they are already orthogonal to each
    // other.
    BOOST_REQUIRE_EQUAL(base.size(), testvec.size());
    for(std::vector<CE3D::Vector>::size_type i = 0; i < base.size(); i++)
    {
        RequireVectorEquality(base[i], testvec[i]);
    }

    // Test 2: Some specific example.
    base.clear();
    CE3D::Vector tmp2(3);

    tmp2(0) = 2;
    tmp2(1) = 0;
    tmp2(2) = 0;
    base.push_back(tmp2);

    tmp2(0) = 1;
    tmp2(1) = 0;
    tmp2(2) = 1;
    base.push_back(tmp2);
    // Yes push back again.
    base.push_back(tmp2);

    tmp2(0) = 0;
    tmp2(1) = 3;
    tmp2(2) = 0;
    base.push_back(tmp2);

    testvec = boost::numeric::ublas::orthogonalize(base);

    std::vector<CE3D::Vector> compare;
    compare.push_back(base[0]);
    tmp2(0) = 0;
    tmp2(1) = 0;
    tmp2(2) = 1;
    compare.push_back(tmp2);
    tmp2(0) = 0;
    tmp2(1) = 0;
    tmp2(2) = 0;
    compare.push_back(tmp2);
    tmp2(0) = 0;
    tmp2(1) = 3;
    tmp2(2) = 0;
    compare.push_back(tmp2);

    BOOST_REQUIRE_EQUAL(base.size(), testvec.size());
    for(std::vector<CE3D::Vector>::size_type i = 0; i < base.size(); i++)
    {
        RequireVectorEquality(compare[i], testvec[i]);
    }



}

// TODO test vector concatenation

BOOST_AUTO_TEST_SUITE_END()

}
}
