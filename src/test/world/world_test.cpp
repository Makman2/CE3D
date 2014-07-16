// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Translation
#include <boost/test/unit_test.hpp>

#include "util/stdinc.h"

#include "world/world.h"
#include "renderer/console/console_material.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(World, TestEnvironment)

/**
 * Tests the construction and destruction of World.
 */
BOOST_AUTO_TEST_CASE(TestWorldConstruction)
{
    CE3D::World<CE3D::ConsoleMaterial> TestWorld;
}

/**
 * Tests getters and setters for the world.
 */
BOOST_AUTO_TEST_CASE(TestWorldGetSet)
{
    CE3D::World<CE3D::ConsoleMaterial> TestWorld;

    BOOST_REQUIRE_EQUAL(TestWorld.GetModels().size(), 0);
}

BOOST_AUTO_TEST_SUITE_END()

}
}