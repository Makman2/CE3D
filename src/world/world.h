// This file is part of CE3D. License: GPL3

#ifndef _WORLD_H
#define _WORLD_H

#include <stdmacro.h>

#include <boost/ptr_container/ptr_list.hpp>

namespace CE3D
{

/**
 * TODO
 */
class World
{
public:
private:
    boost::ptr_list<Model> m_ModelList;
}

}

#endif /* _WORLD_H */
