// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OrthogonalProjection
#include <boost/test/unit_test.hpp>

#include "util/stdinc.h"

#include "transformation/custom.h"
#include "util/CE3D_matrix.h"
#include "test/transformation/transformation_test.h"

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
    CE3D::Matrix TestMatrix =
        boost::numeric::ublas::identity_matrix<CE3D::ModelDataType>(4,4);
    TestMatrix(2,3) = 4;
    BOOST_REQUIRE_NO_THROW(TestUnit =
                           new CE3D::Transformation::Custom(TestMatrix));

    RequireMatrixEquality(TestMatrix, TestUnit->GetMatrix());
    BOOST_REQUIRE_NO_THROW(delete TestUnit);
}

BOOST_AUTO_TEST_CASE(TestCustomGetSet)
{
    CE3D::Transformation::Custom TestUnit;


    CE3D::Matrix TestMatrix =
        boost::numeric::ublas::identity_matrix<CE3D::ModelDataType>(4,4);
    TestMatrix(2,3) = 4;
    TestUnit.SetMatrix(TestMatrix);
    RequireMatrixEquality(TestMatrix, TestUnit.GetMatrix());
}

BOOST_AUTO_TEST_CASE(TestCustomAppend)
{
    CE3D::Transformation::Custom TestUnit;

    CE3D::Matrix TestMatrix =
        boost::numeric::ublas::identity_matrix<CE3D::ModelDataType>(4,4);

    TestUnit.SetMatrix(TestMatrix);
    TestUnit.AppendTransformation(TestUnit);

    RequireMatrixEquality(TestMatrix, TestUnit.GetMatrix());
}

BOOST_AUTO_TEST_SUITE_END()

}
}
