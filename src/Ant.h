#ifndef Ant
#define Ant

#include "Tile.h"

enum Orientation {
  UP,
  RIGHT,
  DOWN,
  LEFT
};

class Tile;
class Ant {
  public:
    Tile* tile;
    Orientation orientation;
    
    Ant(Tile* t, Orientation o);
    void move();
};

#endif
