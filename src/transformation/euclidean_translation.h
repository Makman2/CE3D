// This file is part of CE3D. License: GPL3

#ifndef _EUCLIDEAN_TRANSLATION_H
#define _EUCLIDEAN_TRANSLATION_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "util/stdmacro.h"

#include "transformation/translation.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A transformation that describes a translation.
 */
class EuclideanTranslation : public Translation
{
private:
    boost::numeric::ublas::vector<ModelDataType> m_TranslationVector;
    boost::numeric::ublas::matrix<ModelDataType> m_Matrix;

public:


    virtual boost::numeric::ublas::vector<ModelDataType>
        GetTranslation() const override;

    /**
     * Sets the euclidean translation-vector.
     *
     * @param value: The euclidean translation-vector.
     */
    virtual void SetTranslation(boost::numeric::ublas::vector<ModelDataType> value);
    
    virtual boost::numeric::ublas::matrix<ModelDataType> GetMatrix() const override;



};

}
}

#endif /* _TRANSLATION_H */
