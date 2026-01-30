#include "Ant.h"
#include "Tile.h"

Ant(Tile* t, Orientation o) {
  tile = t;
  orientation = o;
}

void move() {
  switch (tile.color) {
    case BLACK:
      tile.color = WHITE;
      
      break;
    case WHITE:
      tile.color = BLACK;

      break;
  }
}
