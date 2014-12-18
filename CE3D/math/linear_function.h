// This file is part of CE3D. License: GPL3

#ifndef CE3D_MATH_LINEAR_FUNCTION_H
#define CE3D_MATH_LINEAR_FUNCTION_H

#include "CE3D/util/CE3D_vector.h"

namespace CE3D
{
namespace Math
{

/**
 * Capsules a linear function (of the form f(x)=ax+b).
 */
class LinearFunction
{
public:
    /**
     * Constructs a new linear function with a gradient and y-axis-intersection
     * of zero. Equally to LinearFunction(0.0f, 0.0f).
     */
    LinearFunction();

    /**
     * Constructs a new linear function with the given gradient and
     * y-axis-intersection.
     *
     * If the gradient is (positive/negative) infinity, the function evaluation
     * returns everytime (+/-) infinity and for the inverse function zero.
     * If the y-axis-intersection is (+/-) infinity, the function results in
     * (+/-) infinity, and the inverse function also infinity but with switched
     * signs (+infinity -> -infinity and vice versa).
     *
     * If both the gradient and y-axis-intersection values are positive or
     * negative infinity the function evaluation result depends on the sign of
     * the given x or y. The result can be infinity or NaN.
     *
     * If NaN is supplied for one parameter, function evaluation (also inverse
     * evaluation) will return NaN.
     *
     * For more details on floating point arithmetic look at the IEEE standards
     * in conjunction with linear functions.
     *
     * @param gradient            The gradient of the linear function.
     * @param y_axis_intersection The y-value where the linear function crosses
     *                            the y-axis.
     */
    LinearFunction(float gradient, float y_axis_intersection);

    /**
     * Constructs a new linear function from two given points.
     *
     * This function sets the gradient to (positive/negative) infinity and the
     * y-axis-intersection to (negative/positive) infinity if the points have
     * the same x-value.
     * If the points are equal or at least one parameter is NaN the gradient
     * and y-axis-intersection will be set to NaN.
     *
     * For more details on special cases (infinity and NaN), see constructor of
     * LinearFunction(float, float) for more information.
     *
     * @param p1x The x-coordinate of the first point.
     * @param p1y The y-coordinate of the first point.
     * @param p2x The x-coordinate of the second point.
     * @param p2y The y-coordinate of the second point.
     */
    LinearFunction(float p1x, float p1y, float p2x, float p2y);

    /**
     * Constructs a new linear function from two given points.
     *
     * If the inputted vectors have a dimension greater than two, the other
     * dimensions are ignored.
     * For special parameter cases see constructor
     * LinearFunction(float, float, float, float).
     *
     * @param p1 The first vector/point.
     * @param p2 The second vector/point.
     */
    LinearFunction(Vector p1, Vector p2);

    virtual ~LinearFunction();
    
    /**
     * Returns the gradient of the linear function.
     *
     * @returns The gradient.
     */
    float GetGradient() const;

    /**
     * Sets the gradient of the linear function.
     *
     * @param value The new gradient.
     */
    void SetGradient(float value);

    /**
     * Returns the y-axis-intersection of the linear function.
     *
     * @returns The y-axis-intersection.
     */
    float GetYAxisIntersection() const;
    /**
     * Sets the y-axis-intersection of the linear function.
     *
     * @param value The new y-axis-intersection.
     */
    void SetYAxisIntersection(float value);

    /**
     * Evaluates the linear function at given parameter.
     *
     * @param x The x-value where to evaluate the function.
     * @returns The result of the linear function at x.
     */
    float FX(float x) const;

    /**
     * Evaluates the inverse linear function at given parameter.
     *
     * @param y The y-value where to evaluate the inverse function.
     * @returns The x value associated to the given y.
     */
    float FY(float y) const;

    /**
     * Evaluates the linear function at given parameter.
     * Invokes LinearFunction::FX(x).
     *
     * @param x The x-value where to evaluate the function.
     * @returns The result of the linear function at x.
     */
    float operator()(float x) const;

private:
    // The gradient of the function.
    float m_Gradient;
    // The y-axis-intersection value.
    float m_YAxisIntersection;
    
};

}
}

#endif /* CE3D_MATH_LINEAR_FUNCTION_H */
