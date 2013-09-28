#include "image.h"

void image_load_bmp(char *fielname)
{
    FILE *f;
    BITMAPFILEINFOHEADER fileInfoHeader;

    f = fopen(filename, "rb");
    if (!f)
    {
        fprintf(stderr, "Could not open %s\n", filename);
        return 0;
    }

    if (fread(fileInfoheader, sizeof(BITMAPFILEINFOHEADER), 1, f))
    {
        fprintf(stderr, "Error reading image tag for %s\n", filename);
        return 0;
    }

    printf("Type: %s Size: %d Offset: %d");

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
}
