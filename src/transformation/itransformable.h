// This file is part of CE3D. License: GPL3

#ifndef _ITRANSFORMABLE_H
#define _ITRANSFORMABLE_H


#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "util/stdmacro.h"

#include "transformation/transformation.h"
#include "transformation/translation.h"
#include "transformation/scale.h"
#include "transformation/rotation.h"

namespace CE3D
{
namespace Transformation
{

class ITransformable
{
public:
    virtual ~ITransformable();
    
    
    /**
     * Transforms all vertices.
     *
     * @param matrix: The matrix to transform with.
     */
    virtual void Transform(Transformation& transformation) = 0;
    /**
     * Translates all vertices.
     *
     * @param translation: The vector that describes the translation.
     */
    virtual void Translate(Translation translation) = 0;
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
    virtual void Scale(CE3D::Transformation::Scale scale) = 0;
    /**
     * Rotates all vertices.
     *
     * @param planar1: The first vector of the rotation plane.
     * @param planar2: The second vector of the rotation plane.
     * @param offset: The offset of the rotation axis.
     * @param angle: The rotation angle.
     */
    virtual void Rotate(Rotation rotation) = 0;
    
};

}
}

#endif /* _ITRANSFORMABLE_H */