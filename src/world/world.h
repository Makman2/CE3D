// This file is part of CE3D. License: GPL3

#ifndef _WORLD_H
#define _WORLD_H

#include <boost/ptr_container/ptr_list.hpp>

#include "util/stdmacro.h"

#include "model/model.h"

namespace CE3D
{

/**
 * TODO
 */
class World
{
public:
private:
    PROPERTY(private, boost::ptr_list<Model>, ModelList);
};

}

#endif /* _WORLD_H */
