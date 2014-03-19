// This file is part of CE3D. License: GPL3

#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdmacros.h>

#include <stdint.h>

typedef uint8_t vector_idx_type;
typedef float   vector_data_type;

typedef struct
{
    vector_data_type* data;
    vector_idx_type dimension;
} CE3D_vector;

#ifdef __cplusplus
extern "C" {
#endif

CE3D_vector CE3D_vector_mul(const CE3D_vector* lhs, const CE3D_vector* rhs);

CE3D_vector CE3D_vector_mul_s(const CE3D_vector* lhs,
                              const vector_data_type rhs);

CE3D_vector CE3D_vector_add(const CE3D_vector* lhs, const CE3D_vector* rhs);

CE3D_vector CE3D_vector_sub(const CE3D_vector* lhs, const CE3D_vector* rhs);


CE3D_vector CE3D_vector_div_s(const CE3D_vector* lhs,
                              const vector_data_type rhs);

#ifdef __cplusplus
}
#endif

#endif /* _VECTOR_H */
