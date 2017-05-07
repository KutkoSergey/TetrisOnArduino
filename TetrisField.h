#include <stdlib.h>

class TetrisField {
private:
  int **matrixField;
  int widthField;
  int heightField;


public:
  TetrisField();
  int ** getFieldMatrix();
  int getWidthField();
  int getHeightField();

  
};


