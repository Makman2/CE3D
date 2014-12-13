// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Translation
#include <boost/test/unit_test.hpp>

#include "CE3D/util/stdinc.h"

#include "CE3D/test/testutilities.h"
#include "CE3D/transformation/translation.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(Translation, TestEnvironment)

/**
 * Tests the construction and destruction of Translation.
 */
BOOST_AUTO_TEST_CASE(TestTranslationConstruction)
{
    std::shared_ptr<CE3D::Transformation::Translation> TestUnit;

    // Parameterless constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Transformation::Translation()));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());

    // Copy constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Transformation::Translation(
        CE3D::Transformation::Translation())));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());

    // (Vector) constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Transformation::Translation(
        CE3D::Vector())));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());
}

/**
 * Tests the getters and setters of Translation.
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

    CE3D::Matrix Comparision = CE3D::IdentityMatrix(4, 4);
    Comparision(0, 3) = 4;
    Comparision(1, 3) = 2;
    Comparision(2, 3) = 7;

    BOOST_CHECK(IsMatrixEqual(Comparision, TestUnit.GetMatrix()));

    BOOST_CHECK(IsVectorEqual(TestUnit.GetTranslation(), Shift));

    BOOST_CHECK(IsVectorEqual(Shift, OrigShift));
}

BOOST_AUTO_TEST_SUITE_END()

}
}
