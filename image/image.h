#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

typedef struct
{
    int size;
    short reserved1;
    short reserved2;
    int offbytes;
} BITMAPFILEINFOHEADER;

typedef struct
{
    int headerSize;
    int width;
    int height;
    short plane;
    short bits_per_pixel;
    int compression_type;
    int image_size;
    int x_pixels_per_meter;
    int y_pixels_per_meter;
    int used_colors;
    int important_colors;
} BITMAPIMAGEHADER;


typedef struct
{
    unsigned char red; /* Red component */
    unsigned char green; /* Green component */
    unsigned char blue; /* Blue component */
    unsigned char alpha; /* Alpha component */
} pixel;

typedef struct
{
    int width;
    int height;
    pixel *data;
} image;
#endif // IMAGE_H_INCLUDED
