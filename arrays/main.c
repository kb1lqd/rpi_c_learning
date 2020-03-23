#include <stdio.h>

void main(void)
{
	#define SIZEOFARRAY 10
	
	int a[SIZEOFARRAY];
	int cnt;
	
	for(cnt = 0; cnt < 10; cnt++)
	{
		a[cnt] = cnt * 10 + cnt;
	}
	
	printf("The first and second elements of a are %d and %d\n",a[0], a[1]);
	printf("Or as pointers, %d and %d\n", *a, *(a+1));
	printf("\nThe entire array is:");
	
	for(cnt=0; cnt < SIZEOFARRAY; cnt++)
	{
		printf("\nElement %d = %d", cnt, a[cnt]);
	}
	
	printf("\n");
}
