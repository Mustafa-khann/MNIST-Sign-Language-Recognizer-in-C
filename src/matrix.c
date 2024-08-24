#include "./include/matrix.h"

#include <stdlib.h>
#include <assert.h>

Matrix* createMatrix(int rows, int cols)
{
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = (float*)calloc(rows * cols, sizeof(float));
    return m;
}

void freeMartix(Matrix *m)
{
    free(m->data);
    free(m);
}

void matrixMultiply(Matrix *a, Matrix *b, Matrix *result)
{
    assert(a->cols == b->rows);
    assert(result->rows == a->rows && result->cols == b->cols);

    for(int i = 0; i<a->rows; i++)
    {
        for(int j = 0; j<b->cols; j++)
            {
                float sum = 0.0f;
                for(int k = 0; k<a->cols; k++)
                    {
                        sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
                    }
                result->data[i * result->cols + j] = sum;
        }
    }
}

void matrixAdd(Matrix *a, Matrix *b, Matrix *result)
{
    assert(a->rows == b->rows && a->cols == b->cols);
    assert(result->rows == a->rows && result->cols == a->cols);

    for(int i = 0; i < a->rows; i++)
    {
        result->data[i] = a->data[i] + b->data[i];
    }
}

void matrixSubtract(Matrix *a, Matrix *b, Matrix *result)
{
    assert(a->rows == b->rows && a->cols == b->cols);
    assert(result->rows == a->rows && result->cols == a->cols);

    for (int i = 0; i < a->rows * a->cols; i++)
    {
        result->data[i] = a->data[i] - b->data[i];
    }
}

void matrixHadamard(Matrix *a, Matrix *b, Matrix *result)
{
    assert(a->rows == b->rows && a->cols == b->cols);
    assert(result->rows == a->rows && result->cols == a->cols);

    for(int i = 0; i<a->rows; i++)
    {
        result->data[i] = a->data[i] * b->data[i];
    }
}

void matrixScalarMultiply(Matrix *m, float scalar)
{
    for (int i = 0; i < m->rows * m->cols; i++)
    {
        m->data[i] *= scalar;
    }
}

void matrixApplyFunction(Matrix *m, float (*func)(float))
{
    for(int i = 0; i < m->rows * m->cols; i++)
    {
        m->data[i] = func(m->data[i]);
    }
}
