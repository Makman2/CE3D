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
public:
private:
    boost::numeric::ublas::vector<ModelDataType> m_TranslationVector;
    boost::numeric::ublas::matrix<ModelDataType> m_Matrix;

    void UpdateMatrix();

public:


    virtual boost::numeric::ublas::vector<ModelDataType> GetTranslation() const
    { return m_TranslationVector; }

    /**
     * Sets the translation-vector.
     *
     * @param shift: The translation-vector.
     */
    virtual void SetTranslation(boost::numeric::ublas::vector<ModelDataType> shift);
    
    virtual void SetTranslation(
        boost::numeric::ublas::vector<ModelDataType> const direction,
        ModelDataType const length);

    virtual boost::numeric::ublas::matrix<ModelDataType> GetMatrix() const override
    { return m_Matrix; }
};

}
}

#endif /* _TRANSLATION_H */
