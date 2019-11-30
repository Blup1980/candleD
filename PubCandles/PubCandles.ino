#include <Adafruit_NeoPixel.h>
#define LED_COUNT 24
#define CANDLE_TABLE_LENGTH 100

#define NB_CHANNEL 6

// Declare our NeoPixel strip object:
Adafruit_NeoPixel neoPixel(LED_COUNT, 10, NEO_GRBW + NEO_KHZ800);
uint32_t rgbcolors[NB_CHANNEL];

uint8_t candleInt[CANDLE_TABLE_LENGTH] = { 40, 40,  40,  40,  40,  40,  40,  36,  41,  37,  37,  41,  43,  45,  42,  42,  43,  42,  41,  39,  40,  43,  43,  51,  52,  51,  47,  44,  47,  47,  51,  45,  46,  45,  48,  46,  55,  37,  55,  57,  48,  53,  49,  52,  49,  53,  48,  48,  40,  54,  43,  55,  35,  46,  48,  43,  48,  48,  46,  46,  42,  46,  45,  45,  46,  41,  48,  51,  49,  45,  45,  43,  41,  43,  43,  42,  44,  43,  43,  42,  41,  40,  40,  41,  45,  45,  44,  43,  40,  44,  42,  41,  40,  40,  40,  40,  40,  40,  40,  40};
uint8_t indexes[NB_CHANNEL];

void setup() {
  // put your setup code here, to run once:
  indexes[0] = 0;
  indexes[1] = 10;
  indexes[2] = 3;
  indexes[3] = 5;
  indexes[4] = 20;
  indexes[5] = 30;
  neoPixel.begin(); 
}

void loop() {
  for (uint8_t i = 0; i < NB_CHANNEL; i++)
  {
    indexes[i] = indexes[i] + 1;
    if (indexes[i] >= CANDLE_TABLE_LENGTH)
      indexes[i] = 0;

    rgbcolors[i] = neoPixel.ColorHSV(10000, 240, candleInt[indexes[i]]);
  }

  for (uint8_t i = 0; i < LED_COUNT; i++)
  {
    uint8_t channel;
    switch(i) {
      case 0:
      case 1:
      case 2:
        channel = 0;
        break;
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
        channel = 1;
        break;
      case 9:
      case 10:
      case 11:
        channel = 2;
        break;
      case 12:
      case 13:
      case 14:
        channel = 3;
        break;
      case 15:
      case 16:
      case 17:
      case 18:
      case 19:
      case 20:
        channel = 4;
        break;
      case 21:
      case 22:
      case 23:
        channel = 5;
        break;
    }

    neoPixel.setPixelColor(i, rgbcolors[channel]);
    
  }
  neoPixel.show();
  
  delay(100);
}
