#include "DIBHeader.h"

bool readDIBHeader(FILE* inputFile, DIBHeader* dibHeader){
	if (fread(&dibHeader->dibHeaderSize, 4, 1, inputFile) == 1){
	if (fread(&dibHeader->pixelWidth, 4, 1, inputFile) == 1){
	if (fread(&dibHeader->pixelHeight, 4, 1, inputFile) == 1){
	if (fread(&dibHeader->colorPlanes, 2, 1, inputFile) == 1){
	if (fread(&dibHeader->bitPerPixel, 2, 1, inputFile) == 1){
	if (fread(&dibHeader->compMethod, 4, 1, inputFile) == 1){
	if (fread(&dibHeader->imgSize, 4, 1, inputFile) == 1){
	if (fread(&dibHeader->HRes, 4, 1, inputFile) == 1){
	if (fread(&dibHeader->VRes, 4, 1, inputFile) == 1){
	if (fread(&dibHeader->numColors, 4, 1, inputFile) == 1){
	if (fread(&dibHeader->numImportantColors, 4, 1, inputFile) == 1){
		return true;
	}}}}}}}}}}}
	return false;
}

bool writeDIBHeader(FILE* outputFile, DIBHeader dibHeader){
	return true;
}
