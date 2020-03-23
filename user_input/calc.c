#include <stdio.h>

int main(int argc, char *argv[])
{
	int result;
	int var1, var2;
	char operator;
	
	sscanf(argv[1], "%d", &var1);
	sscanf(argv[2], "%s", &operator);
	sscanf(argv[3], "%d", &var2);	
	
	if(operator == '+')
	{
		result = var1 + var2;
	}
	else if(operator == '-')
	{
		result = var1 - var2;
	}
	else if(operator == '/')
	{
		result = var1 / var2;
	}
	else if(operator == 'x')
	{
		result = var1 * var2;
	}
	else
	{
		printf("Invalid\n");
	}
	
	printf("%d\n", result);
}
