#ifndef ANT
#define ANT

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
    Tile* current;
    Orientation orientation;

    Ant() {
      Tile temp = Tile(Color::BLACK);
      current = &temp;
      orientation = UP;
    }
    
    Ant(Tile* t, Orientation o) {
      delete current;

      current = t;
      orientation = o;
    }

    void move() {
      if (current->color == Color::WHITE) {
        switch (orientation) {
          case UP:
            orientation = RIGHT;
            break;
          case RIGHT:
            orientation = DOWN;
            break;
          case DOWN:
            orientation = LEFT;
            break;
          case LEFT:
            orientation = UP;
            break;
        }  
      } else {
        switch (orientation) {
          case UP:
            orientation = LEFT;
            break;
          case LEFT:
            orientation = DOWN;
            break;
          case DOWN:
            orientation = RIGHT;
            break;
          case RIGHT:
            orientation = UP;
            break;
        }
      }

      current->swap_color();
    }
};

#endif
