// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_TRANSFORMATION_H
#define CE3D_TRANSFORMATION_TRANSFORMATION_H

#include "util/stdinc.h"

#include "util/CE3D_matrix.h"

namespace CE3D
{
namespace Transformation
{

/**
 * An abstract class that is the base class of any transformation that fits
 * into a matrix.
 *
 * A transformation can usually be used to transform a set of vectors (e.g.
 * representing a model) through a matrix. An ITransformable object can be
 * transformed with any derived object.
 *
 * However if your derivative is a simple transformation (e.g. a translation)
 * you probably want to calculate the matrix lazy only if its needed and
 * provide more abstract, processing-friendlier information (in this case the
 * translation vector) to a transformable object.
 *
 * If a transformable object does not support your transformation in an
 * abstract way it will fall back to the transformation matrix.
 */
class Transformation
{
protected:
    /**
     * The matrix that represents the transformation.
     *
     * This is mutable since it is implicit information which is lazy filled in
     * a const function if needed.
     */
    mutable Matrix m_Matrix;

    /**
     * Determines whether the matrix was modified and needs to be updated.
     *
     * Set this to true if you set information that implicitly changes the
     * matrix so you can recalculate it lazy.
     */
    mutable bool m_NeedUpdate;

    /**
     * Updates the matrix.
     *
     * This function is invoked by GetMatrix if m_NeedUpdate is true. It is
     * used to calculate implicit information (the matrix) lazy because it is
     * rarely needed for some transformations.
     */
    virtual void UpdateMatrix() const = 0;
public:
    Transformation();
    inline virtual
    ~Transformation() {};
    
    /**
     * Returns the matrix that represents the linear transformation.
     *
     * @return The matrix.
     */
    virtual Matrix const&
    GetMatrix() const;

};


}
}

#endif /* CE3D_TRANSFORMATION_ITRANSFORMABLE_H */
