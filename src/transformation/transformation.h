// This file is part of CE3D. License: GPL3

#ifndef _TRANSFORMATION_H
#define _TRANSFORMATION_H

#include <boost/numeric/ublas/matrix.hpp>

#include "util/stdmacro.h"

namespace CE3D
{
namespace Transformation
{
class Transformation
{
public:
    virtual boost::numeric::ublas::matrix<ModelDataType> GetMatrix() = 0;
    
};


}
}

#endif /* _ITRANSFORMABLE_H */