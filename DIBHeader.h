#ifndef DIBHEADER_H
#define DIBHEADER_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
	unsigned int dibHeaderSize;
	int pixelWidth;
	int pixelHeight;
	unsigned short colorPlanes;
	unsigned short bitPerPixel;
	unsigned int compMethod;
	unsigned int imgSize;
	unsigned int HRes;
	unsigned int VRes;
	unsigned int numColors;
	unsigned int numImportantColors;
}DIBHeader;

bool readDIBHeader(FILE* inputFile, DIBHeader* dibHeader);
bool writeDIBHeader(FILE* outputFile, DIBHeader dibHeader);

#endif
