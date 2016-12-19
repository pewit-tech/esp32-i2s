#ifndef _I2S_FREERTOS_H_
#define _I2S_FREERTOS_H_

//Parameters for the I2S DMA behaviour
#define I2SDMABUFCNT (14)			//Number of buffers in the I2S circular buffer
#define I2SDMABUFLEN (128*2)		//Length of one buffer, in 32-bit words.
#define I2S_DEFAULT_SAMPLE_RATE  (44100)


void i2sInit();
void i2sSetRate(int rate, int enaWordlenFuzzing);
void i2sPushSample(unsigned int sample);
long i2sGetUnderrunCnt();


#endif