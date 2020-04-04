/* This is a simple test program to first interface to the mcp9808 
 * using the BCM2835 library.
*/
#include <stdio.h>
#include <bcm2835.h>

#define SLAVE_ADDRESS 0x18
#define BUF_SIZE 4

int main (void)
{
	
	//function variables
	char current_reg = 0x07;
	int clk_div = 2000;
	char rxbuf[BUF_SIZE]; //buffer for received values
	int mcp9808_reason_code;
	int i; //for loops
	
	for(i=0;i<BUF_SIZE;i++)
	{
		rxbuf[i] = 0x00;
	}
	
	//initialize bcm2835 library
	if(!bcm2835_init())
	{
		printf("Failed to initialize.");
		return 1;
	}	
	
	//start MCP9808 initialization
	printf("Initializing MCP9808.\n");

	//initialize I2C pins for I2C operations (ALT mode)
	bcm2835_i2c_begin();
	
	printf("Step 1\n");
	
	//set slave address
	bcm2835_i2c_setSlaveAddress(SLAVE_ADDRESS);

	printf("Step 2\n");

	
	//set baudrate (standard is 100kbaud)
	bcm2835_i2c_setClockDivider(clk_div);
    fprintf(stderr, "Clock divider set to: %d\n", clk_div);
	//bcm2835_i2c_set_baudrate(100000);
	
	printf("Reading Device %d Register %d\n", SLAVE_ADDRESS, current_reg);

	mcp9808_reason_code = bcm2835_i2c_read(rxbuf, 4);
	printf("REASON CODE: %d\n", mcp9808_reason_code);
	
	for(i=0;i<BUF_SIZE;i++)
	{
		printf("RXBUF[%d] Value: %d\n", i, rxbuf[i]);
	}
	
	
	bcm2835_i2c_end();
	bcm2835_close();
	
	
	

		return 0;
}
