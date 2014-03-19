// This file is part of CE3D. License: GPL3

#ifndef _MODEL_H
#define _MODEL_H

#include <stdmacros.h>

#include "../utils/array_list.h"

/**
 * TODO
 */
typedef enum
{
    TRIANGLE,
    LINE,
    POINT
} CE3D_vector_format;

/**
 * TODO
 */
typedef struct
{
    CE3D_vector_format type;
    char* name;
    bool visible;

    /**
     * This is a list of CE3D_vector's. The position is the index.
     */
    CE3D_array_list vectors;

    /**
     * This is a list of
     * a) triangles
     * b) lines
     * or
     * c) points
     * 
     * (They all use indexed vectors.)
     */
    CE3D_array_list vector_index_list;
} CE3D_model;


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* _MODEL_H */
