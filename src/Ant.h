#ifndef ANT
#define ANT

#include "Tile.h"

#include <iostream>

enum Orientation {
  UP,
  RIGHT,
  DOWN,
  LEFT
};

class Tile;
class Ant {
  public:
    Orientation orientation;

    int ant_pos_x;
    int ant_pos_y;
    
    Ant() :
      orientation(UP),
      ant_pos_y(0),
      ant_pos_x(0)
    {}
    
    Ant(int y, int x, Orientation o) :
      orientation(o),
      ant_pos_y(y),
      ant_pos_x(x)
    {}

    void set_pos(int y, int x) {
      ant_pos_y = y;
      ant_pos_x = x;
    }
};

#endif
