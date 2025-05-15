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
/* ---#SBUS --- */
