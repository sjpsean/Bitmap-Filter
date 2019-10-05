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
	if(toupper(*argV[2]) != 'T' && toupper(*argV[2]) != 'G' && toupper(*argV[2]) != 'S'){
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
	//Reading BMP Header
	BMPHeader bmpHeader;
	if(readBMPHeader(inputFile, &bmpHeader)){
		printf("BMP Header successfully read\n");
	}
	else{
		printf("Failed to read BMP Header\n");
		return 3;
	}	
	//readDIBHeader
	DIBHeader dibHeader;
	if(readDIBHeader(inputFile, &dibHeader)){
		printf("DIB Header successfully read\n");
	}
	else{
		printf("Failed to read DIB Header\n");
		return 4;
	}
	//move file pointer to where the pixel starts.
	fseek(inputFile, bmpHeader.pixelOffset, SEEK_SET); //file pointer goes to the front + offset
	//readPixel
	Pixel pixel;
	if(readPixel(inputFile, &pixel)){
		printf("B: %d\nG: %d\nR: %d\n", pixel.B, pixel.G, pixel.R);
	}
	


	/* int sum = (r+g+b)/3works because 
	 * r+g+b/3will be calculated first before it stores the result.
	 * */
	return 0;
}
