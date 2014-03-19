// This file is part of CE3D. License: GPL3

#ifndef _ARRAY_LIST_H
#define _ARRAY_LIST_H

#include <stdmacros.h>

#include "list.h"

/**
 * TODO
 */
typedef struct
{
    void* data;
    size_type type_size;
    list_idx_type size;
} CE3D_array_list;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* _ARRAY_LIST_H */
