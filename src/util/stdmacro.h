// This file is part of CE3D. License: GPL3

#ifndef _STDMACRO_H
#define _STDMACRO_H

#include <stdint.h>
#include "CE3D_config.h"

/**
 * TODO comment
 */
#define UNUSED __attribute__((unused))

/**
 * TODO doxygen comment
 * TODO doxygen comments for getters and setters
 */
#define RW_PROPERTY(scope, type, name)                                         \
scope:                                                                         \
    type m_ ## name;                                                           \
public:                                                                        \
    inline type Get ## name() const                                            \
    {                                                                          \
        return m_ ## name;                                                     \
    }                                                                          \
                                                                               \
    inline type Set ## name(const type copy)                                   \
    {                                                                          \
        m_ ## name = copy;                                                     \
    }                                                                          \
scope:

/**
 * TODO doxygen comment
 * TODO doxygen comments for getters and setters
 */
#define R_PROPERTY(scope, type, name)                                          \
scope:                                                                         \
    type m_ ## name;                                                           \
public:                                                                        \
    inline type Get ## name() const                                            \
    {                                                                          \
        return m_ ## name;                                                     \
    }                                                                          \
scope:

/**
 * TODO doxygen comment
 * TODO doxygen comments for getters and setters
 */
#define W_PROPERTY(scope, type, name)                                          \
scope:                                                                         \
    type m_ ## name;                                                           \
public:                                                                        \
    inline type Set ## name(const type copy)                                   \
    {                                                                          \
        m_ ## name = copy;                                                     \
    }                                                                          \
scope:

/**
 * TODO doxygen comment
 * TODO doxygen comments for getters and setters
 */
#define PROPERTY(scope, type, name)                                            \
scope:                                                                         \
    type m_ ## name;

#endif /* _STDMACRO_H */
