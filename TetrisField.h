#include <stdlib.h>
#include "TetrisItem.h"
class TetrisField {
    
private:
  int **matrixField;
  int widthField;
  int heightField;
  TetrisItem *tetrisItem;

public:
  TetrisField();
  int ** getFieldMatrix();
  int getWidthField();
  int getHeightField();
  TetrisItem * getTetrisItem();
  bool isNullTetrisItem();
  void doStep();
  bool hasCollisions(TetrisItem * item) ;
  bool hasCollisions(int xPoints, int yPoints) ;
  int getBlockType (int xBlocks, int yBlocks) ;
  
};


