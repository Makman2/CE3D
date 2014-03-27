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
public:
    /**
     * Returns the matrix that represents the linear transformation.
     *
     * @return The matrix.
     */
    virtual boost::numeric::ublas::matrix<ModelDataType> const&
    GetMatrix() const = 0;

    virtual
    ~Transformation();
};


}
}

#endif /* CE3D_TRANSFORMATION_ITRANSFORMABLE_H */
