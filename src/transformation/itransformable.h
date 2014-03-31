// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_ITRANSFORMABLE_H
#define CE3D_TRANSFORMATION_ITRANSFORMABLE_H

#include "util/stdinc.h"

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
    virtual
    ~ITransformable();

    /**
     * Transforms all vertices.
     *
     * @param matrix: The matrix to transform with.
     */
    virtual void
    Transform(Transformation const& transformation) = 0;

    /**
     * Translates all vertices.
     *
     * @param translation: The vector that describes the translation.
     */
    virtual void
    Translate(Translation const& translation) = 0;

    /**
     * Scales all vertices.
     *
     * @param factor: The factor to scale with.
     */
    virtual void
    Scale(ModelDataType const factor) = 0;

    /**
     * Scales all vertices.
     *
     * @param scale: The vector that describes the scale.
     */
    virtual void
    Scale(CE3D::Transformation::Scale const& scale) = 0;

    /**
     * Rotates all vertices.
     *
     * @param planar1: The first vector of the rotation plane.
     * @param planar2: The second vector of the rotation plane.
     * @param offset: The offset of the rotation axis.
     * @param angle: The rotation angle.
     */
    virtual void
    Rotate(Rotation const& rotation) = 0;
    
};

}
}

#endif /* CE3D_TRANSFORMATION_ITRANSFORMABLE_H */
