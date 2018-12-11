#include "image.h"

SDL_Texture* image_to_texture(SDL_Renderer* renderer, char* path, int* width, int* height, int* channels, int desiredChannels)
{
    unsigned char* source_pixels = stbi_load(path, width, height, channels, desiredChannels);

    int w = *width;
    int h = *height;
    int ch = *channels;

    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, w, h);
    SDL_Log(path);

    int* pitch = malloc(sizeof(int));
    unsigned char* destination_pixels = malloc(sizeof(w * h * ch));
    
    SDL_LockTexture(texture, NULL, (void **)&destination_pixels, pitch);
    SDL_memcpy(destination_pixels, source_pixels, w * h * ch);
    SDL_UnlockTexture(texture);

    stbi_image_free(source_pixels);
    free(pitch);
    return texture;
}

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

    free(pitch);
    SDL_UnlockTexture(toReturn);
    return toReturn;
}