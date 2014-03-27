// This file is part of CE3D. License: GPL3

#include <math.h>

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
        // Orthonormalize planar vectors.
        ModelDataType norm1 = boost::numeric::ublas::norm_2(m_Planar1);
        boost::numeric::ublas::vector<ModelDataType> normvec1 = (m_Planar1 / norm1);
        
        // Project the second planar vector onto the first one.
        boost::numeric::ublas::vector<ModelDataType> normvec2 = m_Planar2 -
            boost::numeric::ublas::inner_prod(m_Planar2, normvec1) * normvec1;

        boost::numeric::ublas::matrix<ModelDataType> v =
            boost::numeric::ublas::outer_prod(normvec1, normvec1) +
            boost::numeric::ublas::outer_prod(normvec2, normvec2);

        boost::numeric::ublas::matrix<ModelDataType> w =
            boost::numeric::ublas::outer_prod(normvec1, normvec2) -
            boost::numeric::ublas::outer_prod(normvec2, normvec1);

        
        boost::numeric::ublas::identity_matrix<ModelDataType> E(w.size1());
    
        m_Matrix = (cos(m_Angle) - 1.0f) * v + sin(m_Angle) * w + E;
    }


}
}
