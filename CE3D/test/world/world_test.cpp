// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE World
#include <boost/test/unit_test.hpp>

#include "CE3D/world/world.h"
#include "CE3D/renderer/console/console_material.h"

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
    std::shared_ptr<CE3D::World<CE3D::ConsoleMaterial> > TestUnit;
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::World<CE3D::ConsoleMaterial>()));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());
}

/**
 * Tests getters and setters for the world.
 */
BOOST_AUTO_TEST_CASE(TestWorldGetSet)
{
    CE3D::World<CE3D::ConsoleMaterial> TestWorld;

    BOOST_CHECK_EQUAL(TestWorld.GetModels().size(), 0);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
