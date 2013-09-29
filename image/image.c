#include <stdio.h>
#include "image.h"

void image_load_bmp(char *filename)
{
    FILE *f;
    BITMAPFILEINFOHEADER fileInfoHeader;
    char type[3];


    f = fopen(filename, "rb");
    if (!f)
    {
        fprintf(stderr, "Could not open %s\n", filename);
    }

    fgets(type, 2, f);
    type[2] = '\0';

    if (fread(&fileInfoHeader, sizeof(BITMAPFILEINFOHEADER), 1, f))
    {
        fprintf(stderr, "Error reading image tag for %s\n", filename);
    }

    printf("Type: %s Size: %d Offset: %d", type, fileInfoHeader.size, fileInfoHeader.offbytes);

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
