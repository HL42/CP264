/**
 * -------------------------------------
 * @file  matrix.c
 * file description
 * -------------------------------------
 * @author HunterLin, 169061939, linx1939@mylaurier
 *
 * @version 2025-01-22
 *
 * -------------------------------------
 */
#include <math.h>
#include "matrix.h"

float norm(float *v, int n) {
    // your implementation
    float result = 0.0;
    for(int i = 0; i < n; i++){
        result = result + v[i] * v[i];
    }

    return sqrt(result);
}

float dot_product(float *v1, float *v2, int n) {
    // your implementation
    float result = 0.0;

    for(int i = 0; i < n; i++){
        result += v1[i] * v2[i];
    }

    return result;

}

void matrix_multiply_vector(float *m, float *v, float *vout, int n) {
    // your implementation
    for(int i = 0; i < n; i++){
        vout[i] = 0.0;
        for(int j = 0; j < n; j++){
            vout[i] += m[i * n + j] * v[j];
        }
    }
    

}

void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n) {
    // your implementation
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m3[i * n + j] = 0.0;
            for(int k = 0; k < n; k++){
                m3[i * n + j] += m1[i * n + k] * m2[k * n + j];
            }
        }
    }
}

 
