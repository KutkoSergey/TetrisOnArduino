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
  
};


