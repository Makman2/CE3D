// This file is part of CE3D. License: GPL3

#ifndef CE3D_TRANSFORMATION_FINAL_TRANSLATION_H
#define CE3D_TRANSFORMATION_FINAL_TRANSLATION_H

#include "CE3D/util/stdinc.h"

#include "CE3D/transformation/translation.h"

namespace CE3D
{
namespace Transformation
{

/**
 * A transformation that describes a translation, but doesn't keep the
 * transformated vector in it's original space. After applying this
 * transformation on your n-dimensional space to translate your first n-1
 * vector components no more translations are possible with the n-1 components,
 * because the new vector room has the dimension n-1.
 *
 * This is useful when e.g. using 4-dimensional transformations for a 3-D
 * space.
 */
class FinalTranslation : public Translation
{
protected:
    /**
     * Updates the matrix.
     */
    virtual void
    UpdateMatrix() const override;

public:
    FinalTranslation();
    /**
     * @param translation The translation vector to initialize the
     * transformation with.
     */
    FinalTranslation(Vector const& translation);
    virtual ~FinalTranslation() override;


};

}
}

#endif
