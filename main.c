#include <stdio.h>
#include "BMPHeader.h"
#include "DIBHeader.h"
#include "Pixel.h"

int main(int argC, char** argV){
	//check if input includes filename.
	if(argC < 3){
		printf("Usage: %s <input_filename> <filter_flag>\n", argV[0]);
		printf("Possible Flags: T, G, S\n");
		return 1;
	}
	*argV[2] = toupper(*argV[2]);
	if(*argV[2] != 'T' && *argV[2] != 'G' && *argV[2] != 'S'){
		printf("Possible Flags: T, G, S\n");
		return 1;
	}
	FILE* inputFile;
	//check if we can open the file
	inputFile = fopen(argV[1], "r");
	if(inputFile == NULL){
		printf("Could not open your file\n");
		return 2;
	}
	char outputFileName[100] = "filtered.bmp";
	FILE* outputFile = fopen(outputFileName, "w");
	//check if we can write the file
	if (!outputFile){
		printf("Failed to write %s\n", outputFileName);
	}


	unsigned int width;
	unsigned int height;
	unsigned short bytePerPixel;
	unsigned short padding;

	//Reading BMP Header
	BMPHeader bmpHeader;
	if(readBMPHeader(inputFile, &bmpHeader)){
		printf("BMP Header successfully read\n");
		if(writeBMPHeader(outputFile, bmpHeader)){
			printf("BMP Header successfully written\n");
		}
		else {
			printf("Failed to write BMP Header\n");
		}
	}
	else{
		printf("Failed to read BMP Header\n");
		return 3;
	}	
	//readDIBHeader
	DIBHeader dibHeader;
	if(readDIBHeader(inputFile, &dibHeader)){
		printf("DIB Header successfully read\n");
		width = dibHeader.pixelWidth;
		height = dibHeader.pixelHeight;
		bytePerPixel = dibHeader.bitPerPixel/8;
		printf("width: %d\nheight: %d\nbyte per pixel: %d\n", width, height, bytePerPixel);

		if(writeDIBHeader(outputFile, dibHeader)){
			printf("DIB Header successfully written\n");
		}
		else {
			printf("Failed to write DIB Header\n");
		}
	}
	else{
		printf("Failed to read DIB Header\n");
		return 4;
	}
	//move file pointer to where the pixel starts.
	fseek(inputFile, bmpHeader.pixelOffset, SEEK_SET); //file pointer goes to the front + offset
	//readPixel
	Pixel pixel;
	
	int widthByte = width*bytePerPixel;
	padding = 4 - (widthByte % 4);
	if(padding == 4){
		padding = 0;
	}
	char originalPixels[height][widthByte + padding];

	// storing original pixels in the 2D array.
	for(int h = 0; h < height; h++){
		int w = 0;
		for(w; w < widthByte; w += 3){
			if(readPixel(inputFile, &pixel)){
				originalPixels[h][w] = pixel.B;
				originalPixels[h][w+1] = pixel.G;
				originalPixels[h][w+2] = pixel.R;
			}
		}
		// add padding at the end of width(row) if there is any.
		for(int p = 0; p < padding; p++){
			originalPixels[h][w + p] = 0;
		}
	}

	const unsigned char intense = 128;
	const unsigned char black = 0;
	const unsigned char white = 255;
	for(int h = 0; h < height; h++){
		int w = 0;
		unsigned char average;
		for(w; w < widthByte; w += 3){
			average = ((originalPixels[h][w] + originalPixels[h][w+1] + originalPixels[h][w+2])-1)/3;
			printf("average of %d, %d, %d = %d\n", 
					originalPixels[h][w], originalPixels[h][w+1], originalPixels[h][w+2], average);
			if(average < intense){
				pixel.B = black;
				pixel.G = black;
				pixel.R = black;
			}
			else{
				pixel.B = white;
				pixel.G = white;
				pixel.R = white;
			}
			if(writePixel(outputFile, pixel)){
				printf("T");
			}
		}
		// add padding at the end of width(row) if there is any.
		for(int p = 0; p < padding; p++){
			if(fprintf(outputFile, "%c", originalPixels[h][w+p])){
				printf("padded");
			}
		}
	}




	/* int sum = (r+g+b)/3works because 
	 * r+g+b/3will be calculated first before it stores the result.
	 * */
	return 0;
}
