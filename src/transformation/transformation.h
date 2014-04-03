// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_TRANSFORMATION_H
#define CE3D_TRANSFORMATION_TRANSFORMATION_H

#include "util/stdinc.h"

#include "util/CE3D_matrix.h"

namespace CE3D
{
namespace Transformation
{
class Transformation
{
protected:
    /// The matrix that represents the transformation.
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
    /**
     * Returns the matrix that represents the linear transformation.
     *
     * @return The matrix.
     */
    virtual Matrix const&
    GetMatrix() const;

    Transformation();

    inline virtual
    ~Transformation() {};
};


}
}

#endif /* CE3D_TRANSFORMATION_ITRANSFORMABLE_H */
