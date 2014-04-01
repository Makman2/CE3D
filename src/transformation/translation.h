// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_TRANSLATION_H
#define CE3D_TRANSFORMATION_TRANSLATION_H

#include "util/stdinc.h"

#include "util/CE3D_vector.h"
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

    Vector m_TranslationVector;
    
    void
    UpdateMatrix();

public:

    /**
     * Returns the translation-vector.
     *
     * @return The translation-vector.
     */
    inline Vector const&
    GetTranslation() const
    { return m_TranslationVector; }

    /**
     * Sets the translation-vector.
     *
     * @param shift: The translation-vector.
     */
    void SetTranslation(Vector const& shift);

    /**
     * Sets the translation-vector by means of direction and length.
     *
     * @param direction: The direction in which to translate.
     * @param length: The distance to translate into direction.
     */
    void SetTranslation(Vector const& direction, ModelDataType const length);

    inline Translation() {};
    inline virtual ~Translation() {};
};

}
}

#endif /* CE3D_TRANSFORMATION_TRANSLATION_H */