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

BOOST_AUTO_TEST_SUITE_END()

}
}
