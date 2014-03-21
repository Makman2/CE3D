// This file is part of CE3D. License: GPL3

#ifndef _UTILS_H
#define _UTILS_H

/**
 * TODO comment
 */
#define UNUSED __attribute__((unused))

// can we use a boost constant for that?
#define PI 3.1415926535

// TODO macros for C wrappers. Expeacially these extern C things, catching all exceptions and so on

#ifdef __cplusplus

/**
 * TODO doxygen comment
 * TODO doxygen comments for getters and setters
 */
#define AUTO_RW_PROPERTY(type, name, orig_scope) type m_ ## (name);                 \
                            public:                                            \
                                    inline type Get ## (name)() const          \
                                    {                                          \
                                        return m_ ## (name);                   \
                                    }                                          \
                                    inline type Set ## (name)(const type copy) \
                                    {                                          \
                                        m_ ## (name) = copy;                   \
                                    }                                          \
                            orig_scope:

/**
 * TODO doxygen comment
 * TODO doxygen comments for getters and setters
 */
#define R_PROPERTY(type, name, orig_scope) type m_ ## (name);                  \
                            public:                                            \
                                    inline type Get ## (name)() const          \
                                    {                                          \
                                        return m_ ## (name);                   \
                                    }                                          \
                            orig_scope:

/**
 * TODO doxygen comment
 * TODO doxygen comments for getters and setters
 */
#define W_PROPERTY(type, name, orig_scope) type m_ ## (name);                  \
                            public:                                            \
                                    inline type Set ## (name)(const type copy) \
                                    {                                          \
                                        m_ ## (name) = copy;                   \
                                    }                                          \
                            orig_scope:
#else

typedef uint8_t bool;
#define true  1
#define false 0
#define TRUE  1
#define FALSE 0

#endif /* __cplusplus */

#endif /* _UTILS_H */
