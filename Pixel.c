#include "Pixel.h"

bool readPixel(FILE* inputFile, Pixel* pixel){
	if(fread(&pixel->B, 1, 1, inputFile) == 1){
	if(fread(&pixel->G, 1, 1, inputFile) == 1){
	if(fread(&pixel->R, 1, 1, inputFile) == 1){
		return true;
	}}}
	else{
		return false;
	}
}

bool writePixel(FILE* outputFile, Pixel pixel){
	if(fwrite(&pixel.B, 1, 1, outputFile) == 1){
	if(fwrite(&pixel.G, 1, 1, outputFile) == 1){
	if(fwrite(&pixel.R, 1, 1, outputFile) == 1){
		return true;
	}}}

	return false;
}
