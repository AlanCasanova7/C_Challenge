#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "math.h"

#define SCREEN_W 800
#define SCREEN_H 600
#define ANGLES_PER_SECOND 6

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

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double delta_time = 0;

    vector_2d_t *origin = malloc(sizeof(vector_2d_t));
    origin->x = SCREEN_W / 2;
    origin->y = SCREEN_H / 2;
    vector_2d_t *line = malloc(sizeof(vector_2d_t));
    line->x = SCREEN_W / 2 + 100;
    line->y = SCREEN_H / 2 + 100;

    while(!quit)
    {
	    SDL_Event event;
      while(SDL_PollEvent(&event))
	    {
		    if(event.type==SDL_QUIT){
			    goto cleanup2;
		    }
	    }

      LAST = NOW;
      NOW = SDL_GetPerformanceCounter();

      delta_time = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency() );

      RotateVectorAroundPoint(origin, line, delta_time * ANGLES_PER_SECOND);

      SDL_SetRenderDrawColor(renderer,0,0,0,255);
	    SDL_RenderClear(renderer);
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
      SDL_RenderDrawLine(renderer, origin->x, origin->y, line->x, line->y);
	    SDL_RenderPresent(renderer);
    }

cleanup2:
	SDL_DestroyRenderer(renderer);
  free(origin);
  free(line);
cleanup1:
	SDL_DestroyWindow(window);
cleanup:
	SDL_Quit();
	return 0;
}