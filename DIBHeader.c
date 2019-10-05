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
	if (fwrite(&dibHeader.dibHeaderSize, 4, 1, outputFile) == 1){
	if (fwrite(&dibHeader.pixelWidth, 4, 1, outputFile) == 1){
	if (fwrite(&dibHeader.pixelHeight, 4, 1, outputFile) == 1){
	if (fwrite(&dibHeader.colorPlanes, 2, 1, outputFile) == 1){
	if (fwrite(&dibHeader.bitPerPixel, 2, 1, outputFile) == 1){
	if (fwrite(&dibHeader.compMethod, 4, 1, outputFile) == 1){
	if (fwrite(&dibHeader.imgSize, 4, 1, outputFile) == 1){
	if (fwrite(&dibHeader.HRes, 4, 1, outputFile) == 1){
	if (fwrite(&dibHeader.VRes, 4, 1, outputFile) == 1){
	if (fwrite(&dibHeader.numColors, 4, 1, outputFile) == 1){
	if (fwrite(&dibHeader.numImportantColors, 4, 1, outputFile) == 1){
		return true;
	}}}}}}}}}}}
	return false;
}
