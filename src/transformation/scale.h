// This file is part of CE3D. License: GPL3

#ifndef _SCALE_H
#define _SCALE_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "util/stdmacro.h"

#include "transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A transformation that describes a scale.
 */
class Scale : public Transformation
{
private:
    boost::numeric::ublas::vector<ModelDataType> m_Scale;
    boost::numeric::ublas::matrix<ModelDataType> m_Matrix;


public:
    inline virtual boost::numeric::ublas::matrix<ModelDataType> GetMatrix()
    {
        return m_Matrix;
    }
    
    /**
     * Sets the scale-vector.
     *
     * @param value: The scale-vector to set.
     */
    void SetScale(boost::numeric::ublas::vector<ModelDataType> value);
    /**
     * Returns the scale vector.
     * 
     * @return The scale-vector.
     */
    boost::numeric::ublas::vector<ModelDataType> GetScale() const;

};

}
}

#endif /* _SCALE_H */
