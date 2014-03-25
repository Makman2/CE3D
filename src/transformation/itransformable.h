// This file is part of CE3D. License: GPL3

#ifndef _ITRANSFORMABLE_H
#define _ITRANSFORMABLE_H


#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "util/stdmacro.h"

namespace CE3D
{
namespace Transformation
{

class ITransformable
{
public:
    virtual ~ITransformable() {};
    
    
    /**
     * Transforms all vertices.
     *
     * @param matrix: The matrix to transform with.
     */
    virtual void Transform(
        const boost::numeric::ublas::matrix<ModelDataType> matrix) = 0;
    /**
     * Translates all vertices.
     *
     * @param translation: The vector that describes the translation.
     */
    virtual void Translate(
        const boost::numeric::ublas::vector<ModelDataType> translation) = 0;
    /**
     * Scales all vertices.
     *
     * @param factor: The factor to scale with.
     */
    virtual void Scale(const ModelDataType factor) = 0;
    /**
     * Scales all vertices.
     *
     * @param scale: The vector that describes the scale.
     */
    virtual void Scale(const boost::numeric::ublas::vector<ModelDataType> scale) = 0;
    /**
     * Rotates all vertices.
     *
     * @param planar1: The first vector of the rotation plane.
     * @param planar2: The second vector of the rotation plane.
     * @param offset: The offset of the rotation axis.
     * @param angle: The rotation angle.
     */
    virtual void Rotate(const boost::numeric::ublas::vector<ModelDataType> planar1,
        const boost::numeric::ublas::vector<ModelDataType> planar2,
        const boost::numeric::ublas::vector<ModelDataType> offset,
        const float angle) = 0;
    
};

}
}

#endif /* _ITRANSFORMABLE_H */