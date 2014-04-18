// This file is part of CE3D. License: GPL3

#include "test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Console
#include <boost/test/unit_test.hpp>

#include "util/stdinc.h"

#include "console/console.h"
#include "util/functor.h"

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
    // also tests the internal reference counting
    CE3D::Console console1, console2, console3;
}

BOOST_AUTO_TEST_CASE(TestConsoleCallback)
{
    CE3D::Console console;
    bool called = false;

    console.Clear();

    console.SetCallback(
                [&]()
                {
                    called = true;
                    console.WriteString("Callback invoked!");
                }
            );

    ungetch('c');

    while(!called);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
