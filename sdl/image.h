#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

struct tagBITMAPFILEINFOHEADER
{
    char[2] type;
    int size;
    short reserved1;
    short reserved2;
    int offbytes;
} BITMAPFILEINFOHEADER;




#endif // IMAGE_H_INCLUDED
