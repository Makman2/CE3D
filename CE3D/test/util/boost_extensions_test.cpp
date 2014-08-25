// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE BoostExtensions
#include <boost/test/unit_test.hpp>

#include "CE3D/util/stdinc.h"

#include "CE3D/test/testutilities.h"

#include "CE3D/util/CE3D_matrix.h"
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
    CE3D::Matrix identity =  CE3D::IdentityMatrix(4, 4);
    CE3D::Matrix inversion(4,4);

    boost::numeric::ublas::invert(identity, inversion);

    RequireMatrixEquality(identity, inversion);

    // TODO test what invert does with wrong dimensions
}

/**
 * Tests the normalize function.
 */
BOOST_AUTO_TEST_CASE(TestNormalize)
{
    CE3D::Vector test(4);
    test(0) = 1;
    test(1) = 1;
    test(2) = 1;
    test(3) = 1;

    CE3D::Vector compare(4);
    compare(0) = 0.5;
    compare(1) = 0.5;
    compare(2) = 0.5;
    compare(3) = 0.5;

    boost::numeric::ublas::normalize(test);
    RequireVectorEquality(test, compare);

    CE3D::Vector test2(3);
    test2(0) = 4;
    test2(1) = 4;
    test2(2) = 2;

    CE3D::Vector compare2(3);
    compare2(0) = 2.0/3.0;
    compare2(1) = 2.0/3.0;
    compare2(2) = 1.0/3.0;

    boost::numeric::ublas::normalize(test2);
    RequireVectorEquality(test2, compare2);
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

    // Copy base for test of array version.
    std::array<CE3D::Vector, 4> basearray;
    for (std::array<CE3D::Vector, 4>::size_type i = 0; i < basearray.size();
         i++)
        basearray[i] = base[i];

    auto testvec = boost::numeric::ublas::orthogonalize(base);
    auto testvecarr = boost::numeric::ublas::orthogonalize(basearray);

    // The vectors should be equal because they are already orthogonal to each
    // other.
    BOOST_CHECK_EQUAL(base.size(), testvec.size());
    BOOST_CHECK_EQUAL(base.size(), testvecarr.size());
    for (std::vector<CE3D::Vector>::size_type i = 0; i < base.size(); i++)
    {
        RequireVectorEquality(base[i], testvec[i]);
        RequireVectorEquality(base[i], testvecarr[i]);
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


    std::vector<CE3D::Vector> compare;
    compare.push_back(base[0]);
    tmp2(0) = 0;
    tmp2(1) = 0;
    tmp2(2) = 1;
    compare.push_back(tmp2);
    compare.push_back(CE3D::ZeroVector(3));
    tmp2(0) = 0;
    tmp2(1) = 3;
    tmp2(2) = 0;
    compare.push_back(tmp2);

    // Copy base for test of array version.
    std::array<CE3D::Vector, 4> basearray2;
    for (std::array<CE3D::Vector, 4>::size_type i = 0; i < basearray.size();
         i++)
        basearray2[i] = base[i];

    testvec = boost::numeric::ublas::orthogonalize(base);
    testvecarr = boost::numeric::ublas::orthogonalize(basearray2);

    BOOST_CHECK_EQUAL(base.size(), testvec.size());
    BOOST_CHECK_EQUAL(base.size(), testvecarr.size());
    for(std::vector<CE3D::Vector>::size_type i = 0; i < base.size(); i++)
    {
        RequireVectorEquality(compare[i], testvec[i]);
        RequireVectorEquality(compare[i], testvecarr[i]);
    }
}

/**
 * Tests the orthonormalize functions.
 */
BOOST_AUTO_TEST_CASE(TestOrthonormalize)
{
    // Test for already orthogonal vectors.
    std::vector<CE3D::Vector> base;
    std::vector<CE3D::Vector> compare;

    CE3D::Vector tmp(4);

    tmp(0) = 2;
    tmp(1) = 0;
    tmp(2) = 0;
    tmp(3) = 0;
    base.push_back(tmp);

    tmp(0) = 0;
    tmp(1) = 4;
    tmp(2) = 0;
    tmp(3) = 0;
    base.push_back(tmp);

    tmp(0) = 0;
    tmp(1) = 0;
    tmp(2) = 9;
    tmp(3) = 0;
    base.push_back(tmp);

    tmp(0) = 0;
    tmp(1) = 0;
    tmp(2) = 0;
    tmp(3) = 100;
    base.push_back(tmp);

    compare.push_back(CE3D::UnitVector(4, 0));
    compare.push_back(CE3D::UnitVector(4, 1));
    compare.push_back(CE3D::UnitVector(4, 2));
    compare.push_back(CE3D::UnitVector(4, 3));

    // Copy base for test of array version.
    std::array<CE3D::Vector, 4> basearray;
    for (std::array<CE3D::Vector, 4>::size_type i = 0; i < basearray.size();
         i++)
        basearray[i] = base[i];

    auto testvec = boost::numeric::ublas::orthonormalize(base);
    auto testvecarr = boost::numeric::ublas::orthonormalize(basearray);

    BOOST_CHECK_EQUAL(base.size(), testvec.size());
    BOOST_CHECK_EQUAL(base.size(), testvecarr.size());
    for (std::vector<CE3D::Vector>::size_type i = 0; i < base.size(); i++)
    {
        RequireVectorEquality(compare[i], testvec[i]);
        RequireVectorEquality(compare[i], testvecarr[i]);
    }

    // Test 2: Some specific example.
    base.clear();
    compare.clear();
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

    // Copy base for test of array version.
    std::array<CE3D::Vector, 4> basearray2;
    for (std::array<CE3D::Vector, 4>::size_type i = 0; i < basearray.size();
         i++)
        basearray2[i] = base[i];

    testvec = boost::numeric::ublas::orthonormalize(base);
    testvecarr = boost::numeric::ublas::orthonormalize(basearray2);

    compare.push_back(CE3D::UnitVector(3, 0));
    compare.push_back(CE3D::UnitVector(3, 2));
    compare.push_back(CE3D::ZeroVector(3));
    compare.push_back(CE3D::UnitVector(3, 1));

    BOOST_CHECK_EQUAL(base.size() - 1, testvec.size());
    BOOST_CHECK_EQUAL(base.size(), testvecarr.size());

    RequireVectorEquality(compare[0], testvec[0]);
    RequireVectorEquality(compare[1], testvec[1]);
    RequireVectorEquality(compare[3], testvec[2]);

    for(std::array<CE3D::Vector, 4>::size_type i = 0;
        i < testvecarr.size() - 1; i++)
    {
        RequireVectorEquality(compare[i], testvecarr[i]);
    }
}

/**
 * Tests is_zero function.
 */
BOOST_AUTO_TEST_CASE(TestIsZero)
{
    CE3D::Vector testvec = CE3D::ZeroVector(4);

    BOOST_CHECK_EQUAL(boost::numeric::ublas::is_zero(testvec), true);

    testvec(3) = 4;

    BOOST_CHECK_EQUAL(boost::numeric::ublas::is_zero(testvec), false);

    testvec(0) = 0.1f;

    BOOST_CHECK_EQUAL(boost::numeric::ublas::is_zero(testvec), false);

    // Change precision.
    // With a precision of 5 the test vector should be recognized as zero.
    BOOST_CHECK_EQUAL(boost::numeric::ublas::is_zero(testvec, 5.0f), true);

    testvec(3) = 0.05f;

    BOOST_CHECK_EQUAL(boost::numeric::ublas::is_zero(testvec, 0.15f), true);
    BOOST_CHECK_EQUAL(boost::numeric::ublas::is_zero(testvec, 0.05f), false);
}

BOOST_AUTO_TEST_CASE(TestMakeZero)
{
    CE3D::Matrix testmatrix(3, 3);
    testmatrix(0, 0) = 1;
    testmatrix(0, 1) = 2;
    testmatrix(0, 2) = 3;
    testmatrix(1, 0) = 0.003;
    testmatrix(1, 1) = 0.02;
    testmatrix(1, 2) = 4;
    testmatrix(2, 0) = 0.001;
    testmatrix(2, 1) = 0;
    testmatrix(2, 2) = 0.05;

    CE3D::Matrix compare(3, 3);
    compare(0, 0) = 1;
    compare(0, 1) = 2;
    compare(0, 2) = 3;
    compare(1, 0) = 0;
    compare(1, 1) = 0;
    compare(1, 2) = 4;
    compare(2, 0) = 0;
    compare(2, 1) = 0;
    compare(2, 2) = 0;

    boost::numeric::ublas::make_zero(testmatrix, 0.1);
    RequireMatrixEquality(testmatrix, compare);
}

// TODO test vector concatenation

BOOST_AUTO_TEST_SUITE_END()

}
}
