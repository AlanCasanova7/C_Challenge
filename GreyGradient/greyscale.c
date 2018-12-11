#include "greyscale.h"

SDL_Texture *make_grey_gradient_texture(SDL_Renderer *renderer){
    int size = 255;
    SDL_Texture *toReturn = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, size, size);
    unsigned char* pixels = NULL;
    int* pitch = malloc(sizeof(int));
    SDL_LockTexture(toReturn, NULL, (void**)&pixels, pitch);

    int i = 0;

    unsigned char color = 0;
    for(; i < size * size * 3; i++){
        if(i % (size * 3) == 0)
        {
            color += 1;
        }
        pixels[i] = color;
    }

    SDL_UnlockTexture(toReturn);
    return toReturn;
}