// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Translation
#include <boost/test/unit_test.hpp>

#include "util/stdinc.h"

#include "util/CE3D_matrix.h"
#include "test/transformation/transformation_test.h"
#include "transformation/translation.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(Transformation, TestEnvironment)

/**
 * Tests the construction and destruction of Translation.
 */
BOOST_AUTO_TEST_CASE(TestTranslationConstruction)
{
    CE3D::Transformation::Translation *TestUnit;
    BOOST_REQUIRE_NO_THROW(TestUnit = new CE3D::Transformation::Translation());
    BOOST_REQUIRE_NO_THROW(delete TestUnit);
}

/**
 * Tests the construction and destruction of Translation.
 */
BOOST_AUTO_TEST_CASE(TestTranslationGetSet)
{
    CE3D::Transformation::Translation TestUnit;

    CE3D::Vector Shift(3);
    Shift[0] = 4.0f;
    Shift[1] = 2.0f;
    Shift[2] = 7.0f;

    CE3D::Vector OrigShift(Shift);

    TestUnit.SetTranslation(Shift);

    CE3D::Matrix Comparision = boost::numeric::ublas::identity_matrix<ModelDataType>(4, 4);
    Comparision(0, 3) = 4;
    Comparision(1, 3) = 2;
    Comparision(2, 3) = 7;

    RequireMatrixEquality(Comparision, TestUnit.GetMatrix());

    RequireVectorEquality(TestUnit.GetTranslation(), Shift);

    RequireVectorEquality(Shift, OrigShift);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
