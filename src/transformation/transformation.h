// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_TRANSFORMATION_H
#define CE3D_TRANSFORMATION_TRANSFORMATION_H

#include <boost/numeric/ublas/matrix.hpp>

#include "util/stdmacro.h"

namespace CE3D
{
namespace Transformation
{
class Transformation
{
protected:
    /// The matrix that represents the transformation.
    Matrix m_Matrix;

public:
    /**
     * Returns the matrix that represents the linear transformation.
     *
     * @return The matrix.
     */
    Matrix const&
    GetMatrix() const
    { return m_Matrix; }

    virtual
    ~Transformation() {};
};


}
}

#endif /* CE3D_TRANSFORMATION_ITRANSFORMABLE_H */
