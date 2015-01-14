// This file is part of CE3D. License: GPL3

#include "CE3D/test/TestEnvironment.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE LinearFunction
#include <boost/test/unit_test.hpp>

#include "CE3D/test/testutilities.h"
#include "CE3D/math/linear_function.h"

namespace CE3D
{
namespace Testing
{

BOOST_FIXTURE_TEST_SUITE(LinearFunction, TestEnvironment)

/**
 * Tests the construction and destruction of LinearFunction.
 */
BOOST_AUTO_TEST_CASE(TestLinearFunctionConstruction)
{
    std::shared_ptr<CE3D::Math::LinearFunction> TestUnit;

    // Parameterless constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Math::LinearFunction()));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());

    // Copy constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Math::LinearFunction(
        CE3D::Math::LinearFunction())));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());

    // (float, float) constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Math::LinearFunction(1.0f, 1.0f)));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());

    // (float, float, float, float) constructor.
    BOOST_REQUIRE_NO_THROW(
        TestUnit.reset(new CE3D::Math::LinearFunction(
        1.0f, 1.0f, 2.0f, 2.0f)));
    BOOST_REQUIRE_NO_THROW(TestUnit.reset());
}

/**
 * Tests the gradient getter and setter.
 */
BOOST_AUTO_TEST_CASE(TestGradientProperty)
{
    CE3D::Math::LinearFunction TestUnit;
    auto randoms = RandomVector(20);
    float gradient;
    for (auto testvalue : randoms)
    {
        BOOST_CHECK_NO_THROW(TestUnit.SetGradient(testvalue));
        BOOST_CHECK_NO_THROW(gradient = TestUnit.GetGradient());
        BOOST_CHECK_EQUAL(gradient, testvalue);
    }
}

/**
 * Tests the y-axis-intersection getter and setter.
 */
BOOST_AUTO_TEST_CASE(TestAxisIntersectionProperty)
{
    CE3D::Math::LinearFunction TestUnit;
    auto randoms = RandomVector(20);
    float yaxis;
    for (auto testvalue : randoms)
    {
        BOOST_CHECK_NO_THROW(TestUnit.SetYAxisIntersection(testvalue));
        BOOST_CHECK_NO_THROW(yaxis = TestUnit.GetYAxisIntersection());
        BOOST_CHECK_EQUAL(yaxis, testvalue);
    }
}


/**
 * Tests the gradient and y-axis-intersect construtor of LinearFunction.
 */
BOOST_AUTO_TEST_CASE(TestLinearFunctionGradientYAxisIntersectInitialization)
{
    auto randoms = RandomVector(40);
    for (std::vector<float>::size_type i = 0; i < randoms.size(); i += 2)
    {
        float gradient = randoms[i];
        float yaxis = randoms[i + 1];
        CE3D::Math::LinearFunction TestUnit(gradient, yaxis);
        BOOST_CHECK_EQUAL(TestUnit.GetGradient(), gradient);
        BOOST_CHECK_EQUAL(TestUnit.GetYAxisIntersection(), yaxis);
    }
}

/**
 * Tests the two-point constructor of LinearFunction.
 */
BOOST_AUTO_TEST_CASE(TestLinearFunctionTwoPointInitialization)
{
    // Do not use loops because the calculation involves a bit more math that
    // should be tested. Copy it here in code and loop with randoms won't
    // really test it.
    constexpr float testvalue_p1x[] = { 1.0f, 3.0f, -10.0f };
    constexpr float testvalue_p1y[] = { 1.0f, 2.0f, -4.0f };
    constexpr float testvalue_p2x[] = { 2.0f, 5.0f, 40.0f };
    constexpr float testvalue_p2y[] = { 2.0f, 10.0f, -14.0f };
    constexpr float desired_gradient[] = { 1.0f, 4.0f, -0.2f };
    constexpr float desired_yaxis[] = { 0.0f, -10.f, -6.0f};

    for (unsigned int i = 0; i < boost::size(desired_gradient); i++)
    {
        CE3D::Math::LinearFunction TestUnit(testvalue_p1x[i], testvalue_p1y[i],
            testvalue_p2x[i], testvalue_p2y[i]);
        BOOST_CHECK_EQUAL(TestUnit.GetGradient(), desired_gradient[i]);
        BOOST_CHECK_EQUAL(TestUnit.GetYAxisIntersection(), desired_yaxis[i]);
    }
}

/**
 * Tests the FX() function and in parallel the ()-operator of LinearFunction.
 */
BOOST_AUTO_TEST_CASE(TestLinearFunctionFXOperatorCall)
{
    CE3D::Math::LinearFunction TestUnit;
    constexpr float testvalue_gradient[] = { 1.0f, 3.0f, -10.0f };
    constexpr float testvalue_yaxis[] = { 1.0f, 2.0f, -4.0f };
    constexpr float testvalue_x1[] = { 1.0f, -7.0f, 11.0f };
    constexpr float testvalue_x2[] = { 5.0f, 3.5f, -4.2f };
    constexpr float desired_fx1[] = { 2.0f, -19.0f, -114.0f};
    constexpr float desired_fx2[] = { 6.0f, 12.5f, 38.0f};

    for (unsigned int i = 0; i < boost::size(desired_fx1); i++)
    {
        TestUnit.SetGradient(testvalue_gradient[i]);
        TestUnit.SetYAxisIntersection(testvalue_yaxis[i]);
        BOOST_CHECK_EQUAL(TestUnit.FX(testvalue_x1[i]), desired_fx1[i]);
        BOOST_CHECK_EQUAL(TestUnit.FX(testvalue_x2[i]), desired_fx2[i]);
        BOOST_CHECK_EQUAL(TestUnit(testvalue_x1[i]), desired_fx1[i]);
        BOOST_CHECK_EQUAL(TestUnit(testvalue_x2[i]), desired_fx2[i]);
    }
}

/**
* Tests the FY() function of LinearFunction.
*/
BOOST_AUTO_TEST_CASE(TestLinearFunctionFY)
{
    CE3D::Math::LinearFunction TestUnit;
    constexpr float testvalue_gradient[] = { 1.0f, 3.0f, -10.0f };
    constexpr float testvalue_yaxis[] = { 1.0f, 2.0f, -4.0f };
    constexpr float testvalue_y1[] = { 1.0f, -7.0f, 11.0f };
    constexpr float testvalue_y2[] = { 5.0f, 3.5f, -4.2f };
    constexpr float desired_fy1[] = { 0.0f, -3.0f, -1.5f };
    constexpr float desired_fy2[] = { 4.0f, 0.5f, 0.02f };

    for (unsigned int i = 0; i < boost::size(desired_fy1); i++)
    {
        TestUnit.SetGradient(testvalue_gradient[i]);
        TestUnit.SetYAxisIntersection(testvalue_yaxis[i]);
        BOOST_CHECK_CLOSE(TestUnit.FY(testvalue_y1[i]), desired_fy1[i],
            0.0001f);
        BOOST_CHECK_CLOSE(TestUnit.FY(testvalue_y2[i]), desired_fy2[i],
            0.0001f);
    }
}

BOOST_AUTO_TEST_SUITE_END()

}
}
