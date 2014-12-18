// This file is part of CE3D. License: GPL3

#include "CE3D/math/linear_function.h"

namespace CE3D
{
namespace Math
{

LinearFunction::LinearFunction()
: LinearFunction(0.0f, 0.0f)
{}

LinearFunction::LinearFunction(float gradient, float y_axis_intersection)
: m_Gradient(gradient)
, m_YAxisIntersection(y_axis_intersection)
{}

LinearFunction::LinearFunction(float p1x, float p1y, float p2x, float p2y)
: m_Gradient((p1y - p2y) / (p1x - p2x))
, m_YAxisIntersection(p1y - m_Gradient * p1x)
{}

LinearFunction::LinearFunction(Vector p1, Vector p2)
: LinearFunction(p1[0], p1[1], p2[0], p2[1])
{}

LinearFunction::~LinearFunction()
{}

float LinearFunction::GetGradient() const
{
    return m_Gradient;
}

void LinearFunction::SetGradient(float value)
{
    m_Gradient = value;
}

float LinearFunction::GetYAxisIntersection() const
{
    return m_YAxisIntersection;
}

void LinearFunction::SetYAxisIntersection(float value)
{
    m_YAxisIntersection = value;
}

float LinearFunction::FX(float x) const
{
    return m_Gradient * x + m_YAxisIntersection;
}

float LinearFunction::FY(float y) const
{
    return (y - m_YAxisIntersection) / m_Gradient;
}

float LinearFunction::operator()(float x) const
{
    return FX(x);
}

}
}
