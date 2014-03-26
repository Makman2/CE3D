// This file is part of CE3D. License: GPL3

#ifndef _CUSTOM_H
#define _CUSTOM_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "util/stdmacro.h"

#include "transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A custom transformation.
 */
class Custom : public Transformation
{
private:
    W_PROPERTY(private, boost::numeric::ublas::matrix<ModelDataType>, Matrix);
    
public:
    inline virtual boost::numeric::ublas::matrix<ModelDataType> GetMatrix()
    {
        return m_Matrix;
    }

};

}
}

#endif /* _CUSTOM_H */
