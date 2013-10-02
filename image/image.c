#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <SDL.h>
#include <gl.h>
#include "image.h"

image *image_load_bmp(char *filename)
{
    FILE *f;
    BITMAPFILEINFOHEADER file_info_header;
    BITMAPIMAGEHADER image_header;
    char tag[3];
    image im;
    memset(tag, 0, 3 * sizeof(char));
    memset(&file_info_header, 0, sizeof(BITMAPFILEINFOHEADER));

    f = fopen(filename, "rb");
    if (!f)
    {
        fprintf(stderr, "Could not open %s\n", filename);
    }

    size_t charsRead = fread(tag, 1, 2, f);
    printf("Chars read: %zu\n", charsRead);

    if (charsRead != 2)
    {
        fprintf(stderr, "Error reading image tag for %s\n", filename);
        fclose(f);
        return;
    }

    if (fread(&file_info_header, sizeof(BITMAPFILEINFOHEADER), 1, f) != 1)
    {
        fprintf(stderr, "Error reading image file header for %s\n", filename);
        fclose(f);
        return;
    }

    if (fread(&image_header, sizeof(BITMAPIMAGEHADER), 1, f) != 1)
    {
        fprintf(stderr, "Error reading image header for %s\n", filename);
        fclose(f);
        return;
    }

    printf("Type: %s Size: %d Offset: %d Width: %d Height: %d BPP: %d\n", tag, file_info_header.size, file_info_header.offbytes, image_header.width, image_header.height, image_header.bits_per_pixel);

    fseek(f, file_info_header.offbytes, SEEK_SET);


    im.width = image_header.width;
    im.height = image_header.height;
    im.data = (pixel *)malloc((size_t)image_header.width * image_header.height);
    memset(im.data, 0, image_header.width * image_header.height);

    if (fread(im.data, sizeof(pixel), image_header.width * image_header.height, f) != image_header.width * image_header.height)
    {
        fprintf(stderr, "Error reading image pixels %s\n", filename);
    }

    fclose(f);

    return &im;
}

// Globals
SDL_Surface *demo_screen;

int main(int argc, char **argv)
{
    SDL_Event event;
    int active = 1;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

    demo_screen = SDL_SetVideoMode(320, 240, 0, SDL_HWSURFACE | SDL_OPENGL);

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
