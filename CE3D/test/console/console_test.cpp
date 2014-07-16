// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Console
#include <boost/test/unit_test.hpp>

#include "CE3D/util/stdinc.h"

#include "CE3D/console/console.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(Console, TestEnvironment)

/**
 * Tests the construction and destruction of Console.
 *
 * This also tests reference counting.
 */
BOOST_AUTO_TEST_CASE(TestConsoleConstruction)
{
    CE3D::Console console1, console2, console3;
}

/**
 * Tests the callback mechanism for the console.
 */
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
