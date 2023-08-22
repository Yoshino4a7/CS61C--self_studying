#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x, unsigned n) {
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
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    // YOUR CODE HERE
			unsigned b=1;
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
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    // YOUR CODE HERE
		unsigned b=1;
				  if(n==0)
					  ;
					  else
	    b=b << (n);
		(*x)=(*x) ^ b;
}

//int main(){
//	
//	unsigned x=12;
//	unsigned * p=&x;
//	printf("get_bit : %d,it should be 0\n",get_bit(12,2));
//	set_bit(p,3,0);
//	printf("set_bit : %d,it should be 8\n",x);
//	x=12;
//	flip_bit(p,1);
//	printf("flip_bit : %d,it should be 13\n",x);
//	
//	return 0;
//}
