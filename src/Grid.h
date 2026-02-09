#ifndef GRID_H
#define GRID_H

#include "Tile.h"
#include "Ant.h"

#include <vector>
#include <iostream>

using namespace std;

class Grid {
  private:
    vector<vector<Tile>> grid;

    Ant* ant;

    int width;
    int height;

  public:
    Grid(int wid, int hei) :
      grid(hei, vector<Tile>(wid)),
      width(wid),
      height(hei)
    {
      for (int y = 0; y < hei; y++) {
        for (int x = 0; x < wid; x++) {
          grid[y][x] = Tile(Color::BLACK);
        }
      }
    }

    Tile* get(int y, int x) {
      return &grid[y][x];
    }

    void add_ant(Ant* a) {
      ant = a;
    }

    void update() {
      std::cout << ant->orientation << " " << ant->ant_pos_y << " " << ant->ant_pos_x << "\n";
      // Change facing direction
      if (grid[ant->ant_pos_y][ant->ant_pos_y].color == Color::WHITE) {
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
      grid[ant->ant_pos_y][ant->ant_pos_y].swap_color();

      std::cout << ant->orientation << " " << ant->ant_pos_y << " " << ant->ant_pos_x << "\n";
      // move forward
      switch (ant->orientation) {
        case UP:
          ant->set_pos(ant->ant_pos_y - 1, ant->ant_pos_x);
          break;
        case RIGHT:
          ant->set_pos(ant->ant_pos_y, ant->ant_pos_x + 1);
          break;
        case DOWN:
          ant->set_pos(ant->ant_pos_y + 1, ant->ant_pos_x);
          break;
        case LEFT:
          ant->set_pos(ant->ant_pos_y, ant->ant_pos_x - 1);
          break;
      }

      std::cout << ant->orientation << " " << ant->ant_pos_y << " " << ant->ant_pos_x << "\n\n";
    }
};

#endif
