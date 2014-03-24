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
 * This macro creates a property with a public getter and setter.
 *
 * @param scope The scope of the property [private, public] this scope will be
 * also active after this declaration.
 * @param type The type of this property.
 * @param name a name. The property will be privately accessible by m_ ## name.
 */
#define RW_PROPERTY(scope, type, name);                                        \
scope:                                                                         \
    type m_ ## name;                                                           \
public:                                                                        \
    /**                                                                        \
     * Generic getter for properties.                                          \
     *                                                                         \
     * @return the property value.                                             \
     */                                                                        \
    inline type Get ## name() const                                            \
    {                                                                          \
        return m_ ## name;                                                     \
    }                                                                          \
                                                                               \
    /**                                                                        \
     * Generic setter for properties.                                          \
     *                                                                         \
     * Please note that the position of the const is necessary for pointers.   \
     * @param the property value.                                              \
     */                                                                        \
    inline void Set ## name(type const copy)                                   \
    {                                                                          \
        m_ ## name = copy;                                                     \
    }                                                                          \
scope:

/**
 * This macro creates a property with a public getter.
 *
 * @param scope The scope of the property [private, public] this scope will be
 * also active after this declaration.
 * @param type The type of this property.
 * @param name a name. The property will be privately accessible by m_ ## name.
 */
#define R_PROPERTY(scope, type, name);                                         \
scope:                                                                         \
    type m_ ## name;                                                           \
public:                                                                        \
    /**                                                                        \
     * Generic getter for properties.                                          \
     *                                                                         \
     * @return the property value.                                             \
     */                                                                        \
    inline type Get ## name() const                                            \
    {                                                                          \
        return m_ ## name;                                                     \
    }                                                                          \
scope:

/**
 * This macro creates a property with a public setter.
 *
 * @param scope The scope of the property [private, public] this scope will be
 * also active after this declaration.
 * @param type The type of this property.
 * @param name a name. The property will be privately accessible by m_ ## name.
 */
#define W_PROPERTY(scope, type, name);                                         \
scope:                                                                         \
    type m_ ## name;                                                           \
public:                                                                        \
    /**                                                                        \
     * Generic setter for properties.                                          \
     *                                                                         \
     * Please note that the position of the const is necessary for pointers.   \
     * @param the property value.                                              \
     */                                                                        \
    inline void Set ## name(type const copy)                                   \
    {                                                                          \
        m_ ## name = copy;                                                     \
    }                                                                          \
scope:


/**
 * This macro creates a property.
 *
 * @param scope The scope of the property [private, public] this scope will be
 * also active after this declaration.
 * @param type The type of this property.
 * @param name a name. The property will be privately accessible by m_ ## name.
 */
#define PROPERTY(scope, type, name);                                           \
scope:                                                                         \
    type m_ ## name

/**
 * Data type for model vectors.
 */
typedef float ModelDataType;
/**
 * Index type for model vectors.
 */
typedef uint32_t ModelIdxType;

#endif /* _STDMACRO_H */
