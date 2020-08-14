#include <stdio.h>
#include "Dependencies/SDL_Headers/SDL.h"

#define bool char
#define true 1
#define false 0
#define main main
void main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Window Go Boom", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    unsigned int* pixels = surface->pixels;
    bool window_is_open = true;

    while (window_is_open) 
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            switch(event.type)
        	{
                case SDL_QUIT:
                    window_is_open = false;
                    break;
        	}
        }


        for (int i = 0; i < 70000; ++i)
        {
            pixels[i] = 0xFFFF;
        }
                
        SDL_UpdateWindowSurface(window);
    }
}