#include "math.h"

void RotateVector(vector_2d_t *toRotate, double rotation)
{
    float origin_x = toRotate->x;
    float origin_y = toRotate->y;

    SDL_Log("%f", origin_x*sin(rotation));

    toRotate->x = (float)(origin_x*cos(rotation) - origin_y*sin(rotation));
    toRotate->y = (float)(origin_y*cos(rotation) + origin_x*sin(rotation));
}

void RotateVectorAroundPoint(vector_2d_t *point, vector_2d_t *toRotate, double rotation){
    float origin_x = toRotate->x - point->x;
    float origin_y = toRotate->y - point->y;

    toRotate->x = (float)(origin_x*cos(rotation) - origin_y*sin(rotation));
    toRotate->y = (float)(origin_y*cos(rotation) + origin_x*sin(rotation));
    
    toRotate->x += point->x;
    toRotate->y += point->y;
}