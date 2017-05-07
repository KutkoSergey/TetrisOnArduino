#include "TetrisItem.h"

TetrisItem::TetrisItem()
{
  sizeMatrixItem = 3;
  this->matrixItem = (int **)malloc(sizeof(int*)*sizeMatrixItem);
  for (int i=0;i<sizeMatrixItem;i++)
    *(this->matrixItem + i) = (int*)malloc(sizeof(int)*sizeMatrixItem);
  generateRandomItem();
}

void TetrisItem::generateRandomItem()
{
  long int  typeItem = random() % 5;
  int  tempMatrixItem[5][3][3] = {
    {{0, 1, 0}, {1, 1, 1}, {0, 0, 0}},
    {{0, 2, 0}, {0, 2, 0}, {0, 2, 2}},
    {{0, 3, 0}, {0, 3, 0}, {3, 3, 0}},
    {{4, 4, 0}, {0, 4, 4}, {0, 0, 0}},
    {{0, 5, 5}, {5, 5, 0}, {0, 0, 0}}};
   
  for(int i=0;i<sizeMatrixItem;i++)
    for(int j=0;j<sizeMatrixItem;j++)
      matrixItem[i][j] = tempMatrixItem[typeItem][i][j];
}

int TetrisItem::getSizeMatrixItem()
{
  return sizeMatrixItem;
}

int ** TetrisItem::getMatrixItem()
{
  return matrixItem;
}
  
void TetrisItem::rotate()
{
  int **tempMatrix;
  tempMatrix = (int **)malloc(sizeof(int*)*sizeMatrixItem);
  for (int i=0;i<sizeMatrixItem;i++)
    *(tempMatrix + i) = (int*)malloc(sizeof(int)*sizeMatrixItem);
    
  for( int i = 0; i < sizeMatrixItem; i++ ) {
      for( int j = 0; j < sizeMatrixItem; i++ ) {
          tempMatrix[ i ][ j ] = matrixItem[ j ][ sizeMatrixItem - 1 - i ];
      }
  }
  matrixItem = tempMatrix;
}


int TetrisItem::getBlockType(int innerXBlock, int innerYBlock)
{
  if( innerXBlock < 0 || sizeMatrixItem <= innerXBlock || innerYBlock < 0 || sizeMatrixItem <= innerYBlock )
  {
      return 0;
  }
  return matrixItem[innerYBlock][innerXBlock];
}

void TetrisItem::setPosition( int xPoints, int yPoints )
{
  xCoordinate = xPoints;
  yCoordinate = yPoints;
}

int TetrisItem::getXCoordinate()
{
  return xCoordinate;
}

int TetrisItem::getYCoordinate()
{
  return yCoordinate;
}

int TetrisItem::getBlockXCoordinate( int innerXBlocks )
{
  int innerXPoints = 10 * innerXBlocks + 5;
  int innerXCenterPoints = 10 * sizeMatrixItem / 2;
  return xCoordinate - innerXCenterPoints + innerXPoints;
}

int TetrisItem::getBlockYCoordinate( int innerYBlocks )
{
  int innerYPoints = 10 * innerYBlocks + 5;
  int innerYCenterPoints = 10 * sizeMatrixItem  / 2;
  return yCoordinate - innerYCenterPoints + innerYPoints;
}


