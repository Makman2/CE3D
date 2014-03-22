// This file is part of CE3D. License: GPL3

#ifndef _FUNCTOR_H
#define _FUNCTOR_H

#include "util/stdmacro.h"

namespace CE3D {

template<typename... Types>
class Functor {
public:
    void operator()(Types... Args) = 0;
};

}

#endif /* _FUNCTOR_H */
