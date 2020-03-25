#include <stdio.h>

//Create a typedef enumerated that can only take on specific valid values 
typedef enum
{
	false,
	true
} BOOLEAN;

void main(void)
{
	BOOLEAN b_var;
	
	b_var = false;
	
	if(b_var == true)
	{
		printf("True\n");
	}
	
	if(b_var == false)
	{
		printf("False\n");
	}
}
