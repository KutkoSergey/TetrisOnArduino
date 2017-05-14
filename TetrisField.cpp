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

  tetrisItem = NULL; 
}

bool TetrisField::isNullTetrisItem()
{
  if(tetrisItem == NULL)
    return true;
  return false;
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

void TetrisField::doStep()
{
  if(isNullTetrisItem())
  {
    tetrisItem = new TetrisItem();
    tetrisItem->setPosition(105, 5);
  }
  //tetrisItem->setPosition(tetrisItem->getXCoordinate(), tetrisItem->getYCoordinate() + 10);
  /*if(tetrisItem->getYCoordinate() == 65)
    tetrisItem = NULL;*/

  TetrisItem *tempItem = tetrisItem;
  tempItem->setPosition (tetrisItem->getXCoordinate(), tetrisItem->getYCoordinate() + 10);  
  if(!hasCollisions(tempItem))
  {
    tetrisItem = tempItem;
  }
  else 
  {   
    while(hasCollisions(tempItem))
    {   
      tempItem->setPosition(tempItem->getXCoordinate(), tempItem->getYCoordinate() - 1 );
    }
    tetrisItem =NULL;
    for(int xBlocks = 0; xBlocks < tempItem->getSizeMatrixItem(); xBlocks++)
    {
      for(int yBlocks = 0; yBlocks < tempItem->getSizeMatrixItem(); yBlocks++)
      {
        int blockType = tempItem->getBlockType(xBlocks, yBlocks);
        if(blockType != 0 )
        {
          int xPoints = tempItem->getBlockXCoordinate(xBlocks);
          int yPoints = tempItem->getBlockYCoordinate(yBlocks);
          matrixField[yPoints / 10][xPoints / 10] = blockType;
        }
      }
    }
  }
}

bool TetrisField::hasCollisions(TetrisItem  *item)
{
  for( int xBlocks = 0; xBlocks < item->getSizeMatrixItem(); ++xBlocks)
  {
    for( int yBlocks = 0; yBlocks < item->getSizeMatrixItem(); ++yBlocks )
    {
      if(item->getBlockType( xBlocks, yBlocks ) > 0 &&
                hasCollisions(item->getBlockXCoordinate(xBlocks), item->getBlockYCoordinate(yBlocks))) 
        {
          return true;
        }
    }
  }
  return false;
}

int TetrisField::getBlockType( int xBlocks, int yBlocks )  {
    static const int BORDER_BLOCK_TYPE = -1;

    if( xBlocks < 0 || getWidthField() <= xBlocks || getHeightField() <= yBlocks ) {
        return BORDER_BLOCK_TYPE;
    } else if( yBlocks < 0 ) {
        return 0;
    }

    return matrixField[ yBlocks ][ xBlocks ];
}

bool TetrisField::hasCollisions( int xPoints, int yPoints ) 
{
    int xBlocks = ( xPoints < 0 ) ? -1 : xPoints / 10;
    int yTopBlocks = yPoints - 5;
    if( getBlockType( xBlocks, yTopBlocks / 10 ) ) {
        return true;
    }
    int yBottomBlocks = yPoints + 5;
    if( yTopBlocks % 10 != 0 && getBlockType( xBlocks, yBottomBlocks / 10 ) ) {
        return true;
    }

    return false;
}
