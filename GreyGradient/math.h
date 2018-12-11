#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vector_2d{
    float x;
    float y;
} vector_2d_t;

void RotateVector(vector_2d_t *toRotate, double rotation);
void RotateVectorAroundPoint(vector_2d_t *point, vector_2d_t *toRotate, double rotation);