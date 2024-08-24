#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

typedef struct {
    int cols;
    int rows;
    float* data;
} Matrix;

Matrix* createMatrix(int rows, int cols);

void freeMartix(Matrix* matrix);
void matrixMultiply(Matrix* a, Matrix* b, Matrix* result);
void matrixAdd(Matrix* a, Matrix* b, Matrix* result);
void matrixSubtract(Matrix* a, Matrix* b, Matrix* result);
void matrixHadamard(Matrix* a, Matrix* b, Matrix* result);
void matrixScalarMultiply(Matrix* m, float scalar);
void matrixApplyFunction(Matrix* m, float (*func)(float));

#endif
