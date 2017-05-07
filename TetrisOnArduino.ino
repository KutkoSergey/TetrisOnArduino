#include <Adafruit_NeoPixel.h>
#include <math.h>
#include "TetrisField.h"
#include "TetrisItem.h"

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(120, PIN, NEO_GRB + NEO_KHZ800);

uint32_t colors[8] = {0, 0x110000, 0x000011, 0x111100, 0x001100, 0x110011, 0x100010, 0x110011};

#define WIDTHPANEL 200
#define HEIGHTPANEL  60
#define SIZEBLOCK 10  


TetrisField *tetrisField;
TetrisItem *tetrisItem;
int xCenterPoint = 105;
int yCenterPoint = 15;
int drawMatrix[6][20];
int matrixElement[3][3] = {{0, 1, 0},
                            {0, 1, 1},
                             {0, 0, 1}};

int fieldMatrix[6][20] ={{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 1, 2, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 4, 0, 0, 0, 0, 4, 2},
                          {1, 4, 2, 2, 3, 2, 2, 2, 5, 5, 1, 1, 4, 4, 5, 5, 4, 4, 4, 0},
                          {3, 3, 3, 5, 4, 4, 4, 4, 5, 5, 0, 1, 4, 0, 5, 5, 0, 3, 3, 0}};
void clearDrawMatrix ()
{
  for (int i=0;i<6;i++)
    for(int j=0;j<20;j++)
      drawMatrix[i][j] = 0;
   
}

void draw()
{
  strip.clear();
  int x[3];
  x[0] = xCenterPoint - 5 - 10;
  x[1] = xCenterPoint - 5 ;
  x[2] = xCenterPoint -5 + 10 ;
  int y[3];
  y[0] = yCenterPoint - 5 - 10;
  y[1] = yCenterPoint - 5 ;
  y[2] = yCenterPoint -5 + 10 ;
   for(int i=0;i<6;i++)
  {
    for(int j=0;j<20;j++)
    {
        drawMatrix[i][j] = fieldMatrix[i][j];
    }
  }
  
  for (int i=0;i<3;i++)
    for(int j=0;j<3;j++)
     drawMatrix[y[i]/10][x[j]/10] = matrixElement[i][j];
  
  
   for(int i=0;i<6;i++)
  {
    for(int j=0;j<20;j++)
    {
        strip.setPixelColor(i*20 +j, colors[drawMatrix[i][j]]);
       // strip.show();
    }
  }
  strip.show();
}

void drawFieldMatrix(int ** tetrisFieldMatrix, TetrisItem *tetrisItem)
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
      if(tetrisItem->getBlockType(j, i)!=0)
       // strip.setPixelColor(20*(tetrisItem->getBlockYCoordinate(i)-5)/10 + (tetrisItem->getBlockXCoordinate(j)-5)/10, colors[tetrisItem->getBlockType(j, i)]);
       strip.setPixelColor(20*(tetrisItem->getBlockYCoordinate(i)-5)/10 + (tetrisItem->getBlockXCoordinate(j)-5)/10, colors[tetrisItem->getBlockType(j, i)]);
    }
  }
  strip.show();
}

void rotate() {
    //Matrix rotatedMatrix( getSizeBlocks() );
    int matrix[3][3];
    for( int i = 0; i < 3; ++i ) {
      //  rotatedMatrix[ i ].resize( getSizeBlocks() );
        for( int j = 0; j < 3; ++j ) {
            matrix[ i ][ j ] = matrixElement[ j ][ 3 - 1 - i ];
        }
    }
      for (int i=0;i<3;i++)
        for(int j=0;j<3;j++)
         matrixElement[i][j] = matrix[i][j];
}

void setup() {
  
  // put your setup code here, to run once:
   Serial.begin(38400); 
 strip.begin();
  strip.show();
tetrisField = new TetrisField();

  tetrisItem = new TetrisItem();
  int x, y;
  tetrisItem->setPosition(105, 15);
  drawFieldMatrix(tetrisField->getFieldMatrix(), tetrisItem);
} 

void loop() {
 /* TetrisField *tetrisField = new TetrisField();

  TetrisItem *tetrisItem = new TetrisItem();
  int x, y;
  tetrisItem->setPosition(105, 15);
  drawFieldMatrix(tetrisField->getFieldMatrix(), tetrisItem);*/
 // clearDrawMatrix();
// draw(
  if(Serial.available())
   {
    byte command = Serial.read();
    switch(command)
    {
      /*case 'l' :  xCenterPoint= xCenterPoint - 10; clearDrawMatrix(); draw(); break;
      case 'r' : xCenterPoint= xCenterPoint + 10; clearDrawMatrix(); draw(); break;
      case 'k' : rotate(); clearDrawMatrix(); draw(); break;*/
      case 'l' : xCenterPoint= xCenterPoint - 10; tetrisItem->setPosition(xCenterPoint, 15);   drawFieldMatrix(tetrisField->getFieldMatrix(), tetrisItem); delay(1000); break;
      case 'r' :xCenterPoint= xCenterPoint + 10; tetrisItem->setPosition(xCenterPoint, 15); drawFieldMatrix(tetrisField->getFieldMatrix(), tetrisItem); delay(1000);break;
      case 'k' : tetrisItem->rotate();   drawFieldMatrix(tetrisField->getFieldMatrix(), tetrisItem); delay(2000); break;
    }
   }
}

