
# I2C Readme

I've connected the MCP9808 I2C sensor to my Raspberry Pi 3 and followed 
the [instructions here](https://diyprojects.io/activate-i2c-bus-raspberry-pi-3-zero/) to setup I2C and test the connection to the sensor
by checking addresses on the bus.

The returned address is (0x18):

```bash
pi@raspberrypi:~ $ sudo i2cdetect -y 1
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- --
10: -- -- -- -- -- -- -- -- 18 -- -- -- -- -- -- --
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
70: -- -- -- -- -- -- -- --
```

This matches the expected address per the [datasheet](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-mcp9808-precision-i2c-temperature-sensor-guide.pdf).
 
