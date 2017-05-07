#include "TetrisField.h"

TetrisField::TetrisField()
{
  heightField = 6;
  widthField = 20; 
  
  this->matrixField = (int **)malloc(sizeof(int*)*heightField);
  for (int i=0;i<widthField;i++)
    *(this->matrixField + i) = (int*)malloc(sizeof(int)*widthField);
    
  for(int i=0;i<heightField;i++)
    for(int j=0;j<widthField;j++)
      this->matrixField[i][j] = 0;

  tetrisItem = new TetrisItem();      
}


int ** TetrisField::getFieldMatrix()
{
  return this->matrixField;
}

int TetrisField::getWidthField()
{
  return widthField;
}

int TetrisField::getHeightField()
{
  return heightField;
}

TetrisItem * TetrisField::getTetrisItem()
{
  return this->tetrisItem;
}

