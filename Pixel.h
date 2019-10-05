#ifndef PIXEL_H
#define PIXEL_H

#include <stdio.h>
#include <stdbool.h>

typedef struct{
	unsigned char B;
	unsigned char G;
	unsigned char R;
}Pixel;

bool readPixel(FILE* inputFile, Pixel* pixel);
bool writePixel(FILE* outputFile, Pixel pixel);

#endif
