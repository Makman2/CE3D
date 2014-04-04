// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Console
#include <boost/test/unit_test.hpp>

#include "util/stdinc.h"

#include "console/console.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(Console, TestEnvironment)

/**
 * Tests the construction and destruction of Console.
 */
BOOST_AUTO_TEST_CASE(TestConsoleConstruction)
{
    CE3D::Console *inst = CE3D::Console::GetInstance();
    BOOST_REQUIRE(inst != nullptr);
    BOOST_REQUIRE(inst == CE3D::Console::GetInstance());
    CE3D::Console::DeleteInstance();
}

BOOST_AUTO_TEST_SUITE_END()

}
}
