<<<<<<< HEAD
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
=======
#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <stdio.h>

/* Color */
typedef struct
{
	unsigned char blue; /* Red component */
	unsigned char green; /* Green component */
	unsigned char red; /* Blue component */
	unsigned char alpha; /* Alpha component */
}color;

/* Image */
typedef struct
{
	int width; /* Width of image */
	int height; /* Height of image */
	color *data; /* Data for image */
}image;


#endif // IMAGE_H_INCLUDED
>>>>>>> 63fa113f32a238d1781eef2299ebb2aa568f1efa
