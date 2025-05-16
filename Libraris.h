/* --- ALEDS --- */
#define USE_HSV
#include <WS2812.h>
WS2812 LED(2);
cRGB color;
/* ---#ALEDS --- */

/* --- microSD --*/
#include <SD.h>
File myFile;
/* ---#microSD --*/

/* --- BME280 ---*/
#include <GyverBME280.h>
GyverBME280 bme;
/* ---#BME280 ---*/

/* --- SBUS --- */
#define ALL_CHANNELS
#include <FUTABA_SBUS.h>
#include <Streaming.h>
FUTABA_SBUS sBus;
byte cnData[6] {0, 0, 0, 0, 0, 0};
byte mode = 0;
unsigned long startTime = 0;
unsigned long start1EngineTime = 0;
unsigned long start2EngineTime = 0;
/* ---#SBUS --- */
