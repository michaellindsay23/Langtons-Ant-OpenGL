#ifndef GRID_H
#define GRID_H

#include "Tile.h"
#include "Ant.h"

#include <vector>
#include <iostream>

using namespace std;

class Grid {
  private:
    vector<vector<Tile*>> grid;

    Ant* ant;

    int width;
    int height;

  public:
    Grid(int wid, int hei) :
      grid(hei, vector<Tile*>(wid)),
      width(wid),
      height(hei)
    {}

    void construct(vector<Tile> tiles) {
      int index = 0;
      for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
          grid[y][x] = &tiles[index];
          index++;
        }
      }
    }

    Tile* get(int y, int x) {
      return grid[y][x];
    }

    void add_ant(Ant* a) {
      ant = a;
    }

    void update() {
      // Change facing direction
      if (grid[ant->ant_pos_y][ant->ant_pos_x]->color == WHITE) {
        switch (ant->orientation) {
          case UP:
            ant->orientation = RIGHT;
            break;
          case RIGHT:
            ant->orientation = DOWN;
            break;
          case DOWN:
            ant->orientation = LEFT;
            break;
          case LEFT:
            ant->orientation = UP;
            break;
        }  
      } else {
        switch (ant->orientation) {
          case UP:
            ant->orientation = LEFT;
            break;
          case LEFT:
            ant->orientation = DOWN;
            break;
          case DOWN:
            ant->orientation = RIGHT;
            break;
          case RIGHT:
            ant->orientation = UP;
            break;
        }
      }

      // Swap color of current tile
      grid[ant->ant_pos_y][ant->ant_pos_x]->swap_color();

      // move forward
      switch (ant->orientation) {
        case UP:
          ant->set_pos(ant->ant_pos_y + 1, ant->ant_pos_x);
          break;
        case RIGHT:
          ant->set_pos(ant->ant_pos_y, ant->ant_pos_x + 1);
          break;
        case DOWN:
          ant->set_pos(ant->ant_pos_y - 1, ant->ant_pos_x);
          break;
        case LEFT:
          ant->set_pos(ant->ant_pos_y, ant->ant_pos_x - 1);
          break;
      }
    }
};

#endif
