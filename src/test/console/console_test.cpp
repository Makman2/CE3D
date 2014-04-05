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

class CallbackClass : public CE3D::Functor<>
{
    void operator()();
};

void CallbackClass::operator()()
{
    CE3D::Console::GetInstance()->WriteString("Keyboard callback!");
}

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

BOOST_AUTO_TEST_CASE(TestKeyboardCallback)
{
    CE3D::Console *inst = CE3D::Console::GetInstance();
    BOOST_REQUIRE(inst != nullptr);
    // TODO set callback
    CallbackClass *tst = new CallbackClass();
    std::shared_ptr<Functor<>> newcb(dynamic_cast<Functor<>*>(tst));
    inst->SetCallback(newcb);
    ungetch('c');
    CE3D::Console::DeleteInstance();

}

BOOST_AUTO_TEST_SUITE_END()

}
}
