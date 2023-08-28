/*********************
**  Mandelbrot fractal
** clang -Xpreprocessor -fopenmp -lomp -o Mandelbrot Mandelbrot.c
** by Dan Garcia <ddgarcia@cs.berkeley.edu>
** Modified for this class by Justin Yokota and Chenyu Shi
**********************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ComplexNumber.h"
#include "Mandelbrot.h"
#include <sys/types.h>


/*
This function returns the number of iterations before the initial point >= the threshold.
If the threshold is not exceeded after maxiters, the function returns 0.
*/
long MandelbrotIterations(long maxiters, ComplexNumber * point, double threshold)
{
    //YOUR CODE HERE

	
	ComplexNumber * z=newComplexNumber(0,0);
	ComplexNumber * z_point=newComplexNumber(Re(point),Im(point));
		
	int i;
	for(i=1;i<maxiters+1;i++){
	
		ComplexNumber * z_pow=ComplexProduct(z,z);
	
		free(z);
		z=ComplexSum(z_pow,z_point);
		
		free(z_pow);
		
		if(ComplexAbs(z) >= threshold){
		
			free(z);
			free(z_point);
			
				
			return i;
		}
		
	}
	

	
	free(z);
	free(z_point);
	return 0;
	
	
  
}

/*
This function calculates the Mandelbrot plot and stores the result in output.
The number of pixels in the image is resolution * 2 + 1 in one row/column. It's a square image.
Scale is the the distance between center and the top pixel in one dimension.
*/
void Mandelbrot(double threshold, long max_iterations, ComplexNumber* center, double scale, long resolution, long * output){
    //YOUR CODE HERE
	double dis = scale/resolution;//the value of linear addding every times
	int len=resolution*2+1;
	ComplexNumber * z;
	int count =0;
	
	double re=0;
	double im=0;
	int i;
	int j;
	for(i=0;i<len;i++){
		for(j=0;j<len;j++)
		{
			re = Re(center)+ (j-resolution)*dis;
			im =Im(center) -(i-resolution)*dis;
			
//				printf("%.2f %.2f\n",re,im);
			z=newComplexNumber(re,im);
			output[count++]=MandelbrotIterations(max_iterations,z,threshold);
			free(z);
		}
	}
	
}


