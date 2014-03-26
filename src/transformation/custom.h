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
    boost::numeric::ublas::matrix<ModelDataType> m_Matrix;
    
public:
    inline virtual boost::numeric::ublas::matrix<ModelDataType> const&
    GetMatrix()
    { return m_Matrix; }

    // TODO setter for matrix

};

}
}

#endif /* _CUSTOM_H */
