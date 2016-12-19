# What is this?

This is a port of FreeRTOS I2S to the Espressif ESP32 chip. Portions of this file come from the Espressif [esp31-smsemu](https://github.com/espressif/esp31-smsemu) project.

For more details check the Pewit Ltd. [ESP32 I2S project page](https://www.pewit.co.uk/esp32/i2s/).

# How does this work?

Basically, to get sound, you need to:
- Connect an I2S codec to the I2S pins on the ESP.
- Start up a thread that's going to do the sound output
- Call I2sInit()
- Call I2sSetRate() with the sample rate you want.
- Generate sound and call i2sPushSample() with 32-bit samples.
The 32bit samples basically are 2 16-bit signed values (the analog values for
the left and right channel) concatenated as (Rout<<16)+Lout

I2sPushSample will block when you're sending data too quickly, so you can just
generate and push data as fast as you can and I2sPushSample will regulate the
speed.

# License/legal

The Espressif support code is licensed under the MIT license, rest of the functions are licensed under Apache license. All 
trademarks, service marks, trade names and product names appearing in these files are the property of 
their respective owner(s).