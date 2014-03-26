// This file is part of CE3D. License: GPL3

#ifndef _DIRECTIONAL_TRANSLATION_H
#define _DIRECTIONAL_TRANSLATION_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "util/stdmacro.h"

#include "transformation/translation.h"


#include "model/model.h"
namespace CE3D
{
namespace Transformation
{

/**
 * A transformation that describes a scale.
 */
class DirectionalTranslation : public Translation
{
private:
    R_PROPERTY(private, boost::numeric::ublas::vector<ModelDataType>, Direction);
    R_PROPERTY(private, ModelDataType, Length);
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
    void SetDirection(boost::numeric::ublas::vector<ModelDataType> value);
    void SetLength(ModelDataType value);


};

}
}

#endif /* _DIRECTIONAL_TRANSLATION_H */
