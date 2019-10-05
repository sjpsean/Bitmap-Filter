#ifndef BMPHEADER_H
#define BMPHEADER_H

#include <stdio.h>
#include <stdbool.h>

typedef struct{
	unsigned char headerField[2];
	unsigned int fileSize;
	unsigned int reservedBytes;
	unsigned int pixelOffset;
}BMPHeader;

bool readBMPHeader(FILE* inputFile, BMPHeader* bmpHeader);
bool writeBMPHeader(FILE* outputFile, BMPHeader bmpHeader);

#endif
