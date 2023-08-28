/*********************
**  Color Map generator
** Skeleton by Justin Yokota
**********************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include "ColorMapInput.h"


/**************
**This function reads in a file name colorfile.
**It then uses the information in colorfile to create a color array, with each color represented by an int[3].
***************/
int** FileToColorMap(char* colorfile, int* colorcount)
{
	//YOUR CODE HERE


	int color_count;
	int sum=0;
	FILE * f=fopen(colorfile,"r");
	fscanf(f,"%d",&color_count);
	
	
		int ** ar=(int **)malloc(sizeof(int*)*color_count);
	for(int i=0;i<color_count;i++){
		
		ar[i]=(int *)malloc(sizeof(int)*3);
		
	}
	
	(*colorcount)=color_count;
	
	

	int i=0;
	while(i<color_count)
	{
		fscanf(f,"%d %d %d",&ar[i][0],&ar[i][1],&ar[i][2]);


		sum++;
		i++;
	}
	
	fclose(f);
	return ar;
//	if(sum!= (*colorcount)){
//		(*colorcount)=sum;
//		return result;
//	}else{
//		return result;
//	}
		
		
		
	
}


