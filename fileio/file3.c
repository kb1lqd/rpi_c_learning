#include <stdio.h>

void main(void)
{
	FILE *fp;
	
	fp = fopen("/home/pi/Documents/git/rpi_c_learning/fileio/output.txt", "ab");
	
	if(fp)
	{
		fprintf(fp, "This is a sentence.\n");
		fclose(fp);
	}
}
