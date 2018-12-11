#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdlib.h>
#include "image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define SCREEN_W 800
#define SCREEN_H 768

#define INIT_ERROR_CHECK(structInitialized, jumpTo)\
if(!structInitialized){\
SDL_Log("structInitialized error %s", SDL_GetError());\
goto jumpTo;\
}

int main(int argc,char **argv)
{
    int quit = 0;
    if(SDL_Init(SDL_INIT_VIDEO)){
		  SDL_Log("init error %s",SDL_GetError());
		  goto cleanup;
    }

    SDL_Window * window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W,SCREEN_H, 0);
    INIT_ERROR_CHECK(window, cleanup1);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);
    INIT_ERROR_CHECK(renderer, cleanup2);

    int width, height, channels;
    int desiredChannels = STBI_rgb;
    SDL_Texture *texture = image_to_texture(renderer, argv[argc - 1], &width, &height, &channels, desiredChannels);

    SDL_Rect *rect = malloc(sizeof(SDL_Rect));
    rect->x = rect->y = 0;
    rect->w = width;
    rect->h = height;

    while(!quit)
    {
	    SDL_Event event;
      while(SDL_PollEvent(&event))
	    {
		    if(event.type==SDL_QUIT)
		    {
			    goto cleanup2;
		    } else if(event.type == SDL_KEYDOWN){
            
        }
	    }

      SDL_SetRenderDrawColor(renderer,0,0,0,255);
	  SDL_RenderClear(renderer);

      SDL_RenderCopy(renderer, texture, NULL, rect);

	SDL_RenderPresent(renderer);
    }

cleanup2:
	SDL_DestroyRenderer(renderer);
cleanup1:
	SDL_DestroyWindow(window);
cleanup:
	SDL_Quit();
	return 0;
}