// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Console
#include <boost/test/unit_test.hpp>

#include "util/stdinc.h"

#include "renderer/console/console_material.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(ConsoleMaterial, TestEnvironment)

/**
 * Tests the construction and destruction of ConsoleMaterial.
 */
BOOST_AUTO_TEST_CASE(TestConsoleMaterialConstruction)
{
    CE3D::ConsoleMaterial mat;
}

/**
 * Tests getter and setter for ConsoleMaterial.
 */
BOOST_AUTO_TEST_CASE(TestConsoleMaterialGetSet)
{
    CE3D::ConsoleMaterial mat(ConsoleColor::CYAN);
    BOOST_REQUIRE_EQUAL(mat.GetColor(), ConsoleColor::CYAN);
    mat.SetColor(ConsoleColor::BLACK);
    BOOST_REQUIRE_EQUAL(mat.GetColor(), ConsoleColor::BLACK);
    // let's check again - the getter shall not change the object
    BOOST_REQUIRE_EQUAL(mat.GetColor(), ConsoleColor::BLACK);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
