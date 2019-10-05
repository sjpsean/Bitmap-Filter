#include "BMPHeader.h"

bool readBMPHeader(FILE* inputFile, BMPHeader* bmpHeader){
	if(fread(&bmpHeader->headerField, 2, 1, inputFile) == 1){
	if(fread(&bmpHeader->fileSize, 4, 1, inputFile) == 1){
	if(fread(&bmpHeader->reservedBytes, 4, 1, inputFile) == 1){
	if(fread(&bmpHeader->pixelOffset, 4, 1, inputFile) == 1){
		return true;
	}}}}
	return false;

};

bool writeBMPHeader(FILE* outputFile, BMPHeader bmpHeader){
	return true;
};
