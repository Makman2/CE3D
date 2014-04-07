// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_POINT_MODEL_H
#define CE3D_MODEL_POINT_MODEL_H

#include "util/stdinc.h"

#include "model/model.h"

namespace CE3D
{

/**
 * This is a model represented by just a set of points.
 */
class PointModel : public Model
{
public:
    ModelType
    GetModelType() const
    { return POINT; }
private:
};

}

#endif /* CE3D_MODEL_POINT_MODEL_H */
