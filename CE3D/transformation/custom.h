// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_CUSTOM_H
#define CE3D_TRANSFORMATION_CUSTOM_H

#include "CE3D/util/stdinc.h"

#include "CE3D/transformation/transformation.h"
#include "CE3D/util/CE3D_matrix.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A custom transformation.
 */
class Custom : public Transformation
{
protected:
    void
    UpdateMatrix() const override
    {}

public:
    Custom() {}
    /**
     * Instantiates a new object.
     *
     * @param matrix: The matrix to initialize the class with.
     */
    Custom(Matrix const& matrix);
    virtual
    ~Custom() {};

    /**
     * Multiplies the matrix of the transformation into the own matrix.
     *
     * @param Trafo The transformation to append.
     */
    void
    AppendTransformation(Transformation const& Trafo);
    /**
     * Sets the transformation matrix.
     *
     * @param value: The new matrix.
     */
    void
    SetMatrix(Matrix const& value)
    { m_Matrix = value; }
};

}
}

#endif /* CE3D_TRANSFORMATION_CUSTOM_H */
