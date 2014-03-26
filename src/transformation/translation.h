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
    /**
     * Returns the euclidean translation-vector.
     *
     * @return: The translation-vector.
     */
    virtual boost::numeric::ublas::vector<ModelDataType> GetTranslation() const = 0;

};

}
}

#endif /* _TRANSLATION_H */
