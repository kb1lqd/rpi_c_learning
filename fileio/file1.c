#include <stdio.h>

void main(void)
{
	FILE *fp;
	int value;
	
	fp = fopen("/home/pi/Documents/git/rpi_c_learning/fileio/input.txt",
	"rb");
	if(fp)
	{
		while(1)
		{
			value = fgetc(fp);
			if(value == EOF) break;
			else printf("%c", value);
		}
		
		fclose(fp);
	}
}
