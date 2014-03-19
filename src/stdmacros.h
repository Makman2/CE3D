// This file is part of CE3D. License: GPL3

#ifndef _STDMACROS_H
#define _STDMACROS_H

/**
 * TODO comment
 */
#define UNUSED __attribute__((unused))

#define PI 3.1415926535

#ifdef __cplusplus

/**
 * TODO doxygen comment
 * TODO doxygen comments for getters and setters
 */
#define AUTO_PROPERTY(type, name, orig_scope) type m_ ## (name);               \
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

#endif

#endif /* _STDMACROS_H */
