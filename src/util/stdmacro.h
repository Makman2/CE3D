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
#define RW_PROPERTY(scope, type, name);                                        \
scope:                                                                         \
    type m_ ## name;                                                           \
public:                                                                        \
    inline type Get ## name() const                                            \
    {                                                                          \
        return m_ ## name;                                                     \
    }                                                                          \
                                                                               \
    inline void Set ## name(const type copy)                                   \
    {                                                                          \
        m_ ## name = copy;                                                     \
    }                                                                          \
scope:

/**
 * TODO doxygen comment
 * TODO doxygen comments for getters and setters
 */
#define R_PROPERTY(scope, type, name);                                         \
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
#define W_PROPERTY(scope, type, name);                                         \
scope:                                                                         \
    type m_ ## name;                                                           \
public:                                                                        \
    inline void Set ## name(const type copy)                                   \
    {                                                                          \
        m_ ## name = copy;                                                     \
    }                                                                          \
scope:

/**
 * TODO doxygen comment
 * TODO doxygen comments for getters and setters
 */
#define PROPERTY(scope, type, name);                                           \
scope:                                                                         \
    type m_ ## name

/**
* TODO doxygen comment
*/
typedef float ModelDataType;
/**
* TODO doxygen comment
*/
typedef uint32_t ModelIdxType;

/**
* TODO doxygen comment
*/
typedef float model_data_t;
/**
* TODO doxygen comment
*/
typedef uint32_t model_idx_t;

#endif /* _STDMACRO_H */
