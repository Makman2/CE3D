// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Translation
#include <boost/test/unit_test.hpp>

#include "util/stdmacro.h"
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

    TestUnit.SetTranslation(Shift);

    CE3D::Matrix Comparision =
        boost::numeric::ublas::zero_matrix<ModelDataType>(4, 4);
    Comparision(0, 0) = Comparision(1, 1)
        = Comparision(2, 2) = Comparision(3, 3) = 1;
    Comparision(0, 3) = 4;
    Comparision(1, 3) = 2;
    Comparision(2, 3) = 7;

    for (ModelIdxType i = 0; i < 4; ++i)
    {
        for (ModelIdxType j = 0; i < 4; ++i)
        {
            BOOST_REQUIRE_EQUAL(Comparision(i,j), TestUnit.GetMatrix()(i,j));
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()

}
}
