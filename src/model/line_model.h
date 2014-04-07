// This file is part of CE3D. License: GPL3

#ifndef CE3D_MODEL_LINE_MODEL_H
#define CE3D_MODEL_LINE_MODEL_H

#include "util/stdinc.h"

#include "model/model.h"

namespace CE3D
{

/**
 * TODO
 */
class LineModel : public Model
{
public:
    ModelType
    GetModelType() const
    { return LINE; }
private:
};

}

#endif /* CE3D_MODEL_LINE_MODEL_H */
