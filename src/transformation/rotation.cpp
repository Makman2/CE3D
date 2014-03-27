// This file is part of CE3D. License: GPL3

#include "transformation/rotation.h"

namespace CE3D
{
namespace Transformation
{

    void Rotation::SetPlanar1(
        boost::numeric::ublas::vector<ModelDataType> const& value)
    {
        UpdateMatrix();
        m_Planar1 = value;
    }
    
    void Rotation::SetPlanar2(
        boost::numeric::ublas::vector<ModelDataType> const& value)
    {
        UpdateMatrix();
        m_Planar2 = value;
    }

    void Rotation::SetOffset(
        boost::numeric::ublas::vector<ModelDataType> const& value)
    {
        UpdateMatrix();
        m_Offset = value;
    }

    void Rotation::SetAngle(float value)
    {
        UpdateMatrix();
        m_Angle = value;
    }

    void Rotation::UpdateMatrix()
    {
        // TODO Implement rotation matrix creation.
    }


}
}
