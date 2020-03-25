#include <stdio.h>

//Define the struct data type
typedef struct
{
	int inval1;
	int inval2;
	int outval;
} MY_DATA;

//Function to manipulate the struct values
//The function expected MY_DATA data type struct to be passed
//as data type address pointer
void add (MY_DATA *d)
{
	d->outval = d->inval1 + d->inval2;
}

void main(void)
{
	//Declare a MY_DATA struct "data"
	MY_DATA data;
	
	//Set the struct values
	data.inval1 = 5;
	data.inval2 = 7;
	
	//Pass the address of the struct to the add function
	add(&data);
	
	printf("The sum of %d and %d is %d\n", data.inval1, data.inval2, data.outval);
}
