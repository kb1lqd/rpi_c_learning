/*
 * main.c
 * 
 * This is a quick loop test program.
 * 
 * 
 */


#include <stdio.h>

int main( void )
{
	
	int a=0;
	
	while(1)
	{
		printf("a is equal to %d\n", a);
		a++;
		
		//Check if a is equal to set number to break the loop
		if(a == 5)
		{
				break;
		}
	}
	
	printf("a is equal to %d and has broken the loop.", a);
	
	return 0;
}

