#include <Adafruit_NeoPixel.h>
#include "TetrisField.h"
#include "TetrisItem.h"

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(120, PIN, NEO_GRB + NEO_KHZ800);

uint32_t colors[8] = {0, 0x110000, 0x000011, 0x111100, 0x001100, 0x110011, 0x100010, 0x110011};

void drawFieldMatrix(int ** tetrisFieldMatrix)
{
  strip.clear();  
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<20;j++)
    {
        strip.setPixelColor(i*20 +j, colors[tetrisFieldMatrix[i][j]]);
    }
  }
}

void setup()
{
  strip.begin();
  strip.show();
}

void loop()
{ 
  TetrisField *tetrisField = new TetrisField();
  draw(tetrisdield->getFieldMatrix());
}

