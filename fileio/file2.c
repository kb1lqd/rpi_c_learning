#include <stdio.h>

void main(void)
{
	FILE *fp;
	int value;
	
	fp = fopen("/home/pi/Documents/git/rpi_c_learning/fileio/output.txt", "wb");
	
	if(fp)
	{
		for(value = 48; value < 68; value++)
		{
			fputc(value, fp);
		}
		fclose(fp);
	}
}
