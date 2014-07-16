// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_IDENTITY_H
#define CE3D_TRANSFORMATION_IDENTITY_H

#include "transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{

/**
 * An identity transformation.
 */
class Identity : public Transformation
{
private:
    Matrix::size_type m_dim1;
    Matrix::size_type m_dim2;

protected:
    virtual void
    UpdateMatrix() const override;

public:
    Identity();
    /**
     * @param dim The dimension of the identity matrix.
     */
    Identity(Matrix::size_type dim);

    /**
     * @param dim1 The row dimension of the identity matrix.
     * @param dim2 The column dimension of the identity matrix.
     */
    Identity(Matrix::size_type dim1, Matrix::size_type dim2);

    /**
     * Returns the row dimension of the identity matrix.
     *
     * @returns The row dimension.
     */
    Matrix::size_type const& GetDimension1() const;

    /**
     * Sets the row dimension of the identity matrix.
     *
     * @param value The new row dimension.
     */
    void SetDimension1(Matrix::size_type value);

    /**
     * Returns the column dimension of the identity matrix.
     *
     * @returns The row dimension.
     */
    Matrix::size_type const& GetDimension2() const;

    /**
     * Sets the column dimension of the identity matrix.
     *
     * @param value The new column dimension.
     */
    void SetDimension2(Matrix::size_type value);
    
};

}
}

#endif /* CE3D_TRANSFORMATION_IDENTITY_H */
