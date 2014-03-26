// This file is part of CE3D. License: GPL3

#ifndef _FUNCTOR_H
#define _FUNCTOR_H

#include "util/stdmacro.h"

namespace CE3D {

template<typename... Types>
class Functor {
public:
	/**
	 * A functor can be treated as a function.
	 */
    virtual void operator()(Types... Args) = 0;
    virtual ~Functor();
};

}

#endif /* _FUNCTOR_H */
