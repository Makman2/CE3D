// This file is part of CE3D. License: GPL3

#include "transformation/rotation.h"

namespace CE3D
{
namespace Transformation
{

    void Rotation::SetPlanar1(Vector const& value)
    {
        m_Planar1 = value;
        m_needUpdate = true;
    }
    
    void Rotation::SetPlanar2(Vector const& value)
    {
        m_Planar2 = value;
        m_needUpdate = true;
    }

    void Rotation::SetOffset(Vector const& value)
    {
        m_Offset = value;
        m_needUpdate = true;
    }

    void Rotation::SetAngle(float value)
    {
        m_Angle = value;
        m_needUpdate = true;
    }

    void Rotation::UpdateMatrix()
    {
        // Orthonormalize planar vectors.
        Vector normvec1 = (m_Planar1 / boost::numeric::ublas::norm_2(m_Planar1));
        
        // Project the second planar vector onto the first one.
        Vector normvec2 = m_Planar2 -
            boost::numeric::ublas::inner_prod(m_Planar2, normvec1) * normvec1;
        ModelDataType norm2 = boost::numeric::ublas::norm_2(normvec2);
        if (norm2 == 0)
        {
            // Throw exception.
            throw std::invalid_argument("Vectors linearly dependent.");
        }
        normvec2 /= boost::numeric::ublas::norm_2(normvec2);

        Matrix v = boost::numeric::ublas::outer_prod(normvec1, normvec1) +
            boost::numeric::ublas::outer_prod(normvec2, normvec2);

        Matrix w = boost::numeric::ublas::outer_prod(normvec1, normvec2) -
            boost::numeric::ublas::outer_prod(normvec2, normvec1);

        
        boost::numeric::ublas::identity_matrix<ModelDataType> E(w.size1());
    
        m_Matrix = (cos(m_Angle) - 1.0f) * v + sin(m_Angle) * w + E;
    }


}
}
