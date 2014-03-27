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

    boost::numeric::ublas::vector<ModelDataType> m_TranslationVector;
    boost::numeric::ublas::matrix<ModelDataType> m_Matrix;

    void UpdateMatrix();

public:

    inline virtual const boost::numeric::ublas::matrix<ModelDataType>&
        GetMatrix() const override
    { return m_Matrix; }


    /**
     * Returns the translation-vector.
     *
     * @return The translation-vector.
     */
    inline const boost::numeric::ublas::vector<ModelDataType>& GetTranslation() const
    { return m_TranslationVector; }

    /**
     * Sets the translation-vector.
     *
     * @param shift: The translation-vector.
     */
    void SetTranslation(boost::numeric::ublas::vector<ModelDataType> const& shift);

    /**
     * Sets the translation-vector by means of direction and length.
     *
     * @param direction: The direction in which to translate.
     * @param length: The distance to translate into direction.
     */
    void SetTranslation(
        boost::numeric::ublas::vector<ModelDataType> const& direction,
        ModelDataType const length);

};

}
}

#endif /* _TRANSLATION_H */
