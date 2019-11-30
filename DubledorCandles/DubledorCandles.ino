#include <Adafruit_NeoPixel.h>
#define LED_COUNT 12
#define CANDLE_TABLE_LENGTH 100

#define NB_CHANNEL 6

// Declare our NeoPixel strip object:
Adafruit_NeoPixel* neoPixels[6];

uint8_t candleInt[CANDLE_TABLE_LENGTH] = { 40, 40,  40,  40,  40,  40,  40,  36,  41,  37,  37,  41,  43,  45,  42,  42,  43,  42,  41,  39,  40,  43,  43,  51,  52,  51,  47,  44,  47,  47,  51,  45,  46,  45,  48,  46,  55,  37,  55,  57,  48,  53,  49,  52,  49,  53,  48,  48,  40,  54,  43,  55,  35,  46,  48,  43,  48,  48,  46,  46,  42,  46,  45,  45,  46,  41,  48,  51,  49,  45,  45,  43,  41,  43,  43,  42,  44,  43,  43,  42,  41,  40,  40,  41,  45,  45,  44,  43,  40,  44,  42,  41,  40,  40,  40,  40,  40,  40,  40,  40};
uint8_t indexes[NB_CHANNEL];

void setup() {
  // put your setup code here, to run once:
  neoPixels[0] = new Adafruit_NeoPixel(LED_COUNT, 2, NEO_GRBW + NEO_KHZ800);
  neoPixels[1] = new Adafruit_NeoPixel(LED_COUNT, 3, NEO_GRBW + NEO_KHZ800);
  neoPixels[2] = new Adafruit_NeoPixel(LED_COUNT, 4, NEO_GRBW + NEO_KHZ800);
  neoPixels[3] = new Adafruit_NeoPixel(LED_COUNT, 5, NEO_GRBW + NEO_KHZ800);
  neoPixels[4] = new Adafruit_NeoPixel(LED_COUNT, 6, NEO_GRBW + NEO_KHZ800);
  neoPixels[5] = new Adafruit_NeoPixel(LED_COUNT, 7, NEO_GRBW + NEO_KHZ800);
  indexes[0] = 0;
  indexes[1] = 25;
  indexes[2] = 80;
  indexes[3] = 5;
  indexes[4] = 50;
  indexes[5] = 60;
  for (uint8_t i = 0; i < NB_CHANNEL; i++)
  {
    neoPixels[i]->begin(); 
  }
}

void loop() {
  for (uint8_t i = 0; i < NB_CHANNEL; i++)
  {
    indexes[i] = indexes[i] + 1;
    if (indexes[i] >= CANDLE_TABLE_LENGTH)
    {
      indexes[i] = 0;
    }
    uint32_t rgbcolor = neoPixels[i]->ColorHSV(10000, 240, candleInt[indexes[i]]);
    neoPixels[i]->fill(rgbcolor);
    neoPixels[i]->show();
  }
  
  delay(100);
}
