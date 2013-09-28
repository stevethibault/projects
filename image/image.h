#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

typedef struct
{
    char type[2];
    int size;
    short reserved1;
    short reserved2;
    int offbytes;
} BITMAPFILEINFOHEADER;


#endif // IMAGE_H_INCLUDED
