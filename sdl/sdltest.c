#include <SDL.h>

// Globals
SDL_Surface *demo_screen;

int main(int argc, char **argv)
{
    SDL_Event event;
    int active = 1;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Could not inititliaze SDL: %s\n", SDL_GetError());

    }

    demo_screen = SDL_SetVideoMode(320, 240, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);

    if (!demo_screen == NULL)
    {
        fprintf(stderr, "Could not set video mode: %s\n", SDL_GetError());
    }

    while (active)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                active = 0;
            }
        }
    }

    SDL_Quit();
    return 0;

}
