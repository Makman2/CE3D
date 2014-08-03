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
 * A transformation that describes a translation.
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
