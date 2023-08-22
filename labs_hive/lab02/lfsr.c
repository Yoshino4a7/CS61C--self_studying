#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

unsigned get_bit(uint16_t x, unsigned n) {
	// YOUR CODE HERE
	// Returning -1 is a placeholder (it makes
	// no sense, because get_bit only returns
	// 0 or 1)
	unsigned b;
	b=1;
	unsigned c;
	b=b<<n;	
	c=x & b;
	if(c==b)
		return 1;
	else if(c==0)
		return 0;
	
	
	return -1;
}
void set_bit(uint16_t * x,
	unsigned n,
	unsigned v) {
		// YOUR CODE HERE
		uint16_t b=1;
		b=b << n;
		unsigned c=(*x);
		if(v==1)
		{
			(*x)=c | b;
			
		}
		else{
			if(get_bit(*x,n)==1){
				(*x)=c ^ b;
			}
		}
	}

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
	
	unsigned b1;
	unsigned b2;
	unsigned result;
	
	b1=get_bit((*reg),0);
	b2=get_bit((*reg),2);
	result=b1 ^ b2;
	
	b1=result;
	b2=get_bit((*reg),3);
	result=b1 ^ b2;

	b1=result;
	b2=get_bit((*reg),5);
	result=b1 ^ b2;
	(*reg) = (*reg)>> 1;
	set_bit(reg,15,result);
	
	
	
}

//int main(){
//	uint16_t a;
//	a=1;
//	uint16_t * reg=&a;
////	set_bit(reg,1,1);
////	printf("%d\n",(*reg));
//	printf("%d\n",1);
//	for(int i=0;i<3;i++){
//			lfsr_calculate(reg);
//			printf("%d\n",(*reg));
//	}
//	
//
//	
//	
//}



