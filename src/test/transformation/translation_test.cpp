// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Translation
#include <boost/test/unit_test.hpp>

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
    CE3D::Transformation::Translation test();
}

BOOST_AUTO_TEST_SUITE_END()

}
}
