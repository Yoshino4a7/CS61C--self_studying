/*********************
**  Color Palette generator
** Skeleton by Justin Yokota
**********************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include "ColorMapInput.h"

//You don't need to call this function but it helps you understand how the arguments are passed in 
void usage(char* argv[])
{
	printf("Incorrect usage: Expected arguments are %s <inputfile> <outputfolder> <width> <heightpercolor>", argv[0]);
}

//Creates a color palette image for the given colorfile in outputfile. Width and heightpercolor dictates the dimensions of each color. Output should be in P3 format
int P3colorpalette(char* colorfile, int width, int heightpercolor, char* outputfile)
{
	//YOUR CODE HERE
	FILE * fp_t =fopen(outputfile,"w");
	
	
	int * colorcount=(int *)malloc(sizeof(int));
	int ** ar = FileToColorMap(colorfile,colorcount);
	fprintf(fp_t,"P3 %d %d 255\n",width,heightpercolor*(*colorcount));
	
	if(ar==NULL||width<1||heightpercolor<1)
	{
		return 1;
	}
	

	for(int i = 0;i<(*colorcount);i++){
			for(int row = 0;row<heightpercolor;row++){
				
				for(int col = 0;col<width;col++){
					
					
					if(col==width-1){
						fprintf(fp_t,"%d %d %d",ar[i][0],ar[i][1],ar[i][2]);
					}else{
						fprintf(fp_t,"%d %d %d ",ar[i][0],ar[i][1],ar[i][2]);
					}
					
					
					
					
				}
				fprintf(fp_t,"\n");
				
			}
		
	}
	for(int i = 0;i<(*colorcount);i++){
		
		
		free(ar[i]);
		
		
		
	}
	free(colorcount);
	free(ar);
	fclose(fp_t);
	
	
	
	
	
	

	
	
	return 0;
}

//Same as above, but with P6 format
int P6colorpalette(char* colorfile, int width, int heightpercolor, char* outputfile)
{
	//YOUR CODE HERE
	
	FILE * fp_t =fopen(outputfile,"w");
	
	
	int * colorcount=(int *)malloc(sizeof(int));
	int ** res = FileToColorMap(colorfile,colorcount);
	fprintf(fp_t,"P6 %d %d 255\n",width,heightpercolor*(*colorcount));
	
	if(res==NULL||width<1||heightpercolor<1)
	{
		return 1;
	}
	
	
	for(int i = 0;i<(*colorcount);i++){
		for(int row = 0;row<heightpercolor;row++){
			
			for(int col = 0;col<width;col++){
				
				
			
					fprintf(fp_t,"%c%c%c",res[i][0],res[i][1],res[i][2]);
			
				
				
				
			}
		
			
		}
		
	}
	for(int i = 0;i<(*colorcount);i++){
		
		
		free(res[i]);
		
		
		
	}
	free(colorcount);
	free(res);
	
	fclose(fp_t);
	
	

	
	

	
	return 0;
}


//The one piece of c code you don't have to read or understand. Still, might as well read it, if you have time.
int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		usage(argv);
		return 1;
	}
	
	int width = atoi(argv[3]);
	int height = atoi(argv[4]);
	char* P3end = "/colorpaletteP3.ppm";
	char* P6end = "/colorpaletteP6.ppm";
	char buffer[strlen(argv[2]) + strlen(P3end)+1];
	sprintf(buffer, "%s%s", argv[2], P3end);
	int failed = P3colorpalette(argv[1], width, height, buffer);
	if (failed)
	{
		printf("Error in making P3colorpalette");
		return 1;
	}
	sprintf(buffer, "%s%s", argv[2], P6end);
	failed = P6colorpalette(argv[1], width, height, buffer);
	if (failed)
	{
		printf("Error in making P6colorpalette");
		return 1;
	}
	printf("P3colorpalette and P6colorpalette ran without error, output should be stored in %s%s, %s%s", argv[2], P3end, argv[2], P6end);
	return 0;
}




