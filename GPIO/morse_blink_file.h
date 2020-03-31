float calc_tdit_ms(float user_wpm);
char* morse_char(char input_char);
void blink_led (char *morse_char_str, int morse_char_len ,int dit_time_ms);


#define PIN RPI_GPIO_P1_11 // GPIO Pin 17
#define MORSE_DIT_UNIT 1
#define MORSE_DAH_UNIT 3
#define MORSE_INTRACHAR_UNIT 1
#define MORSE_INTERCHAR_UNIT 3
#define MORSE_INTERWORD_UNIT 7


//define characters

