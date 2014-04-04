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

/**
 * Interface for something on that you can apply transformations.
 */
class ITransformable
{
public:
    virtual
    ~ITransformable();

    /**
     * Transforms all vertices.
     *
     * @param transformation: The matrix to transform with packed in a
     * transformation.
     */
    virtual void
    Transform(Transformation const& transformation) = 0;

    /**
     * Translates all vertices.
     *
     * @param translation: The translation to apply.
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
     * @param scale: The scale transformation to apply.
     */
    virtual void
    Scale(CE3D::Transformation::Scale const& scale) = 0;

    /**
     * Rotates all vertices.
     *
     * @param rotation: The rotation to apply.
     */
    virtual void
    Rotate(Rotation const& rotation) = 0;
    
};

}
}

#endif /* CE3D_TRANSFORMATION_ITRANSFORMABLE_H */
