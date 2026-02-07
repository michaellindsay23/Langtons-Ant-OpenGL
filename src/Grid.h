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

  public:
    int width;
    int height;

    Ant ant;
    int ant_pos_x;
    int ant_pos_y;

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

    void add_ant(int ant_pos_y, int ant_pos_x, Orientation o) {
      ant = Ant(&grid[ant_pos_y][ant_pos_x], o);

      this->ant_pos_y = ant_pos_y;
      this->ant_pos_x = ant_pos_x;
    }

    void update() {
      ant.move();

      switch (ant.orientation) {
        case UP:
          ant_pos_y -= 1;
          break;
        case RIGHT:
          ant_pos_x += 1;
          break;
        case DOWN:
          ant_pos_y += 1;
          break;
        case LEFT:
          ant_pos_x -= 1;
          break;
      }

      std::cout << ant_pos_x << "\n";

      ant.current = &grid[ant_pos_y][ant_pos_x];
    }
};

#endif
