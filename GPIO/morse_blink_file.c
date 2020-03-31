/*
 * This program is to create a simple text input to morse code output function.
 * It should accept a string variable, and speed (words per minute) and
 * toggle ON a GPIO with the respective morse code at the input WPM value.
 * 
*/

#include <stdio.h>
#include <bcm2835.h>
#include  <stdlib.h>
#include <string.h>
#include "morse_blink.h"
#include <ctype.h>

// PARIS is 50 units of morse code length where a dit is one unit
// tdit(s) = 60/(50*speedwpm)

//variables
char input_string[255];
char *input_wpm_raw;
int input_wpm;



int main(int argc, char *argv[])
{
	
	//Setup Variables
	FILE *fp;
	int i; // for loops
	
	//fp = fopen("message.txt", "r");
	fp = fopen(argv[1], "r");
	fgets(input_string, 255, (FILE*)fp); 
	
	
	//Converter input message to all lowercase
	//input_string = strlwr(input_string);
	printf("%d\n",strlen(input_string));
	for(i=0; i<strlen(input_string); i++)
	{
		input_string[i] = tolower(input_string[i]);
	}



	printf("Input arguments: %s, %s\n", argv[1], argv[2]);
	printf("Morse Blink\n");
	
	//get user input values stored into global variables
	//strcpy(input_string, argv[1]);
	input_wpm_raw = argv[2];
	input_wpm = atoi(input_wpm_raw);
	
	printf("Input String: %s\n", input_string);
	printf("WPM: %d of dit length %f seconds \n", input_wpm, calc_tdit_ms(input_wpm));

	//Check for GPIO initialization
	if(!bcm2835_init())
	{
		printf("Failed to initialize.");
		return 1;
	}	
	
	//Set the pin to be an output
	bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_write(PIN, LOW); // Set pin LOW
	
	//Check input string to blink LED in morse code at specific WPM rate		

	for(i=0;i<strlen(input_string);i++)
	{
		blink_led(morse_char(input_string[i]), strlen(morse_char(input_string[i])), calc_tdit_ms(input_wpm)*1000);		
	}

	//Close GPIO library ports
	bcm2835_close();
	
	//Return
	return 0;
}

float calc_tdit_ms(float user_wpm)
{
	//This function returns the time in ms of a dit.
	float temp;
	temp = 60/(50*user_wpm);
	return temp;

}

void blink_led(char* morse_char_str, int morse_char_len ,int dit_time_ms)
{
	
	//printf("Character: %s\n", morse_char_str);
	
	//Check if character is space between word or a valid character
	if(morse_char_str[0]==' ')
	{
		printf("-SPACE-\n");
		bcm2835_delay(dit_time_ms*MORSE_INTERWORD_UNIT);
	}
	else
	{
		int i;
		for(i=0;i<morse_char_len;i++)
		{
			switch(morse_char_str[i])
			{
				case '.':
					bcm2835_gpio_write(PIN, HIGH);
					bcm2835_delay(dit_time_ms*MORSE_DIT_UNIT);
					bcm2835_gpio_write(PIN, LOW);
					bcm2835_delay(dit_time_ms*MORSE_INTRACHAR_UNIT);
					break;
				case '-':
					bcm2835_gpio_write(PIN, HIGH);
					bcm2835_delay(dit_time_ms*MORSE_DAH_UNIT);
					bcm2835_gpio_write(PIN, LOW);
					bcm2835_delay(dit_time_ms*MORSE_INTRACHAR_UNIT);
					break;
				default:
					printf("UNKNOWN CHARACTER!");
			}
		}
		//Delay the standard time between each character in a word
		bcm2835_delay(dit_time_ms*MORSE_INTERCHAR_UNIT);
	}
}

char* morse_char(char input_char)
{
	//This function inputs a single character and transmits its morse code value
	switch(input_char)
	{
		case 'a':
			return ".-";
		case 'b':
			return "-...";
		case 'c':
			return "-.-.";
		case 'd':
			return "-..";
		case 'e':
			return ".";
		case 'f':
			return "..-.";
		case 'g':
			return "--.";
		case 'h':
			return "....";
		case 'i':
			return ".";
		case 'j':
			return ".---";
		case 'k':
			return "-.-";
		case 'l':
			return ".-..";
		case 'm':
			return "--";
		case 'n':
			return "-.";
		case 'o':
			return "---";
		case 'p':
			return ".--.";
		case 'q':
			return "--.-";
		case 'r':
			return ".-.";
		case 's':
			return "...";
		case 't':
			return "-";
		case 'u':
			return "..-";
		case 'v':
			return "...-";
		case 'w':
			return ".--";
		case 'x':
			return "-..-";
		case 'y':
			return "-.--";
		case 'z':
			return "--..";
		case '0':
			return "-----";	
		case '1':
			return ".----";	
		case '2':
			return "..---";	
		case '3':
			return "...--";	
		case '4':
			return "....-";	
		case '5':
			return ".....";	
		case '6':
			return "-.....";	
		case '7':
			return "--....";	
		case '8':
			return "---..";	
		case '9':
			return "----.";	
		case ' ':
			return " ";		
		default:
			return "";
	}
}
