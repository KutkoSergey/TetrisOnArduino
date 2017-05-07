#include <stdlib.h>


class TetrisItem 
{
private:
  int **matrixItem;  
  int yCoordinate;
  int xCoordinate;
  int sizeMatrixItem;

public:
  TetrisItem();
  void generateRandomItem(); 
  int getSizeMatrixItem();
  int ** getMatrixItem();   
  void rotate();
  void setPosition(int x, int y);
  int getXCoordinate();
  int getYCoordinate();
  int getBlockType(int innerXBlock, int innerYBlock);
  int getBlockXCoordinate(int innerXBlock);
  int getBlockYCoordinate(int innerYBlock);
  
};

