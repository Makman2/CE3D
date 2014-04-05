// This file is part of CE3D. License: GPL3

#ifndef CE3D_UTIL_FUNCTOR_H
#define CE3D_UTIL_FUNCTOR_H

namespace CE3D {

/**
 * Anything that has operator() with any parameters.
 */
template<typename... Types>
class Functor {
public:
    /**
     * A functor can be treated as a function.
     *
     * @param Args Any arguments to the functions.
     */
    virtual void
    operator()(Types... Args) = 0;

    virtual
    ~Functor();
};

}

#endif /* CE3D_UTIL_FUNCTOR_H */
