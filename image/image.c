#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "image.h"

void image_load_bmp(char *filename)
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


    pixels = (pixel *)malloc((size_t)image_header.width * image_header.height);
    memset(pixels, 0, image_header.width * image_header.height);

    if (fread(image.data, sizeof(pixel), image_header.width * image_header.height, f) != image_header.width * image_header.height)
    {
        fprintf(stderr, "Error reading image pixels %s\n", filename);
    }

    fclose(f);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: imageinfo filename");
        return 1;
    }

    image_load_bmp(argv[1]);

    return 0;
}
