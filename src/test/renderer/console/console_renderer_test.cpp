// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Console
#include <boost/test/unit_test.hpp>

#include "util/stdinc.h"

#include "renderer/console/console_renderer.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(ConsoleRenderer, TestEnvironment)

/**
 * Tests the construction and destruction of ConsoleRenderer.
 */
BOOST_AUTO_TEST_CASE(TestConsoleRendererConstruction)
{
    // also tests the internal reference counting
    CE3D::ConsoleRenderer renderer;
}

BOOST_AUTO_TEST_SUITE_END()

}
}
