// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_ROTATION_H
#define CE3D_TRANSFORMATION_ROTATION_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "util/stdmacro.h"

#include "transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A transformation that describes a scale.
 */
class Rotation : public Transformation
{
private:
    // TODO getter
    boost::numeric::ublas::vector<ModelDataType> m_Planar1;
    // TODO getter
    boost::numeric::ublas::vector<ModelDataType> m_Planar2;
    // TODO getter
    boost::numeric::ublas::vector<ModelDataType> m_Offset;
    // TODO getter
    float m_Angle;

    boost::numeric::ublas::matrix<ModelDataType> m_Matrix;

    void UpdateMatrix();

public:
    inline virtual boost::numeric::ublas::matrix<ModelDataType> const&
        GetMatrix() const
    { return m_Matrix; }
    
    /**
     * Sets the first plane-vector.
     *
     * Sets the first planar vector, needed for the description of the rotation
     * plane.
     *
     * @param value: The plane-vector to set.
     */
    void SetPlanar1(boost::numeric::ublas::vector<ModelDataType> const& value);
    /**
     * Sets the second plane-vector.
     *
     * Sets the second planar vector, needed for the description of the rotation
     * plane.
     *
     * @param value: The plane-vector to set.
     */
    void SetPlanar2(boost::numeric::ublas::vector<ModelDataType> const& value);
    /**
     * Sets the offset of the rotation.
     *
     * @param value: The offset-vector to set.
     */
    void SetOffset(boost::numeric::ublas::vector<ModelDataType> const& value);
    /**
     * Sets the rotation angle.
     *
     * @param value: The rotation angle.
     */  
    void SetAngle(float value);


};

}
}

#endif /* CE3D_TRANSFORMATION_ROTATION_H */
