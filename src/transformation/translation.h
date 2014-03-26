// This file is part of CE3D. License: GPL3

#ifndef _TRANSLATION_H
#define _TRANSLATION_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "util/stdmacro.h"

#include "transformation/transformation.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A transformation that describes a translation.
 */
class Translation : public Transformation
{
private:
    R_PROPERTY(private, boost::numeric::ublas::vector<ModelDataType>, Translation);
    boost::numeric::ublas::matrix<ModelDataType> m_Matrix;


public:
    inline virtual boost::numeric::ublas::matrix<ModelDataType> GetMatrix()
    {
        return m_Matrix;
    }
    
    /**
     * Sets the translation-vector.
     *
     * @param value: The translation-vector to set.
     */
    void SetTranslation(boost::numeric::ublas::vector<ModelDataType> value);


};

}
}

#endif /* _TRANSLATION_H */
