// This file is part of CE3D. License: GPL3

#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdmacros.h>

#include <stdint.h>

#include "vector.h"

typedef uint8_t matrix_idx_type;
typedef float   matrix_data_type;

typedef struct
{
    matrix_data_type** data;
    matrix_idx_type width, height;
} CE3D_matrix;

#ifdef __cplusplus
extern "C" {
#endif

CE3D_matrix CE3D_matrix_mul(const CE3D_matrix* lhs, const CE3D_matrix* rhs);

CE3D_matrix CE3D_matrix_mul_s(const CE3D_matrix* lhs,
                              const matrix_data_type rhs);

CE3D_matrix CE3D_matrix_add(const CE3D_matrix* lhs, const CE3D_matrix* rhs);

CE3D_matrix CE3D_matrix_sub(const CE3D_matrix* lhs, const CE3D_matrix* rhs);

CE3D_matrix CE3D_matrix_div_s(const CE3D_matrix* lhs,
                              const matrix_data_type rhs);

CE3D_matrix CE3D_matrix_mul_v(const CE3D_matrix* lhs, const CE3D_vector* rhs);

#ifdef __cplusplus
}
#endif

#endif /* _MATRIX_H */
