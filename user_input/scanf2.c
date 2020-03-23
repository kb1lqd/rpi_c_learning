#include <stdio.h>

void main(void)
{
		char input[256], name[256];
		int age;
		
		printf("What is your name, user?\n");
		fgets(input, 256, stdin);
		sscanf(input, "%s", name);
		
		printf("Hello %s. How old are you?\n", input);
		scanf("%d", &age);
		
		printf("%s, you are %d years old.\n", input, age);
		
}
