// This file is part of CE3D. License: GPL3

#ifndef _STDMACRO_H
#define _STDMACRO_H

#include <stdint.h>
#include "CE3D_config.h"

/**
 * TODO
 */
#define GENERATE_SINGLETON(object)                                             \
private:                                                                       \
    /**                                                                        \
     * This is a singleton.                                                    \
     */                                                                        \
    static object* s_Instance;                                                 \
    /**                                                                        \
     * This is a singleton.                                                    \
     */                                                                        \
    object();                                                                  \
    /**                                                                        \
     * This is a singleton.                                                    \
     */                                                                        \
    object(const object& rhs);                                                 \
    /**                                                                        \
     * This is a singleton.                                                    \
     */                                                                        \
    ~object();                                                                 \
public:                                                                        \
    /**                                                                        \
     * Returns the same instance of this object every time.                    \
     */                                                                        \
    static object* GetInstance()                                               \
    {                                                                          \
        if (s_Instance == NULL)                                                \
        {                                                                      \
            s_Instance = new object();                                         \
        }                                                                      \
        return s_Instance;                                                     \
    }

/**
 * This macro creates a property with a public getter and setter.
 *
 * @param scope The scope of the property [private, protected] this scope will
 * be also active after this declaration.
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
 * @param scope The scope of the property [private, protected] this scope will
 * be also active after this declaration.
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
 * @param scope The scope of the property [private, protected] this scope will
 * be also active after this declaration.
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
 * @param scope The scope of the property [private, protected] this scope will
 * be also active after this declaration.
 * @param type The type of this property.
 * @param name a name. The property will be privately accessible by m_ ## name.
 */
#define PROPERTY(scope, type, name);                                           \
scope:                                                                         \
    type m_ ## name

/**
 * Data type for model vectors.
 */
using ModelDataType = float;
/**
 * Index type for model vectors.
 */
using ModelIdxType = uint32_t;

#endif /* _STDMACRO_H */
