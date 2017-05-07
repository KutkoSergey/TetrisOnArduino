#include <Adafruit_NeoPixel.h>
#include "TetrisField.h"

#define PIN 6

TetrisField *tetrisField;

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

  for(int i=0;i<3;i++)
   {
     for(int j=0;j<3;j++)
     {
      if(tetrisField->getTetrisItem()->getBlockType(j, i)!=0)
        strip.setPixelColor(20*(tetrisField->getTetrisItem()->getBlockYCoordinate(i)-5)/10 
        + (tetrisField->getTetrisItem()->getBlockXCoordinate(j)-5)/10, 
        colors[tetrisField->getTetrisItem()->getBlockType(j, i)]);
     }
  }
  strip.show();
}

void setup()
{
    Serial.begin(9600);
  randomSeed(analogRead(0));

  tetrisField = new TetrisField();
  strip.begin();
  strip.show();
}

void loop()
{ 
  tetrisField->getTetrisItem()->generateRandomItem();
  tetrisField->getTetrisItem()->setPosition(105, 15);
  drawFieldMatrix(tetrisField->getFieldMatrix());
  delay(1000);
}

