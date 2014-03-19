// This file is part of CE3D. License: GPL3

#ifndef _LIST_H
#define _LIST_H

#include <stdmacros.h>

#include "list.h"

/**
 * TODO
 */
typedef struct
{
    CE3D_list_element* prev;
    CE3D_list_element* next;
    void* content;
} CE3D_list_element;

/**
 * TODO
 */
typedef struct
{
    CE3D_list_element* first;
    CE3D_list_element* last;
    size_type type_size;
    list_idx_type size;
} CE3D_doubly_linked_list;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates an empty doubly linked list.
 * 
 * @param type_size The size of the data type used for this list.
 * @return The newly created list.
 */
CE3D_doubly_linked_list* CE3D_doubly_linked_list_ctor(size_t type_size);

/**
 * Appends data at the end of the list.
 *
 * @return the modified list.
 */
CE3D_doubly_linked_list* push_back(CE3D_doubly_linked_list* self, void* data);

/**
 * Appends data at the beginning of the list.
 *
 * @return the modified list.
 */
CE3D_doubly_linked_list* push_front(CE3D_doubly_linked_list* self, void* data);

#ifdef __cplusplus
}
#endif

#endif /* _LIST_H */
