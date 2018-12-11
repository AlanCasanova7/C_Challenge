#include <SDL.h>
#include <stdlib.h>
#include "stb_image.h"

SDL_Texture* make_grey_gradient_texture(SDL_Renderer *renderer);
SDL_Texture* image_to_texture(SDL_Renderer *renderer, char *path, int *width, int *height, int *channels, int desiredChannels);