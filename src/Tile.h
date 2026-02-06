#ifndef TILE
#define TILE

enum class Color {
  WHITE,
  BLACK
};

class Tile {
  public:
    Color color;

    Tile() {
      color = Color::BLACK;
    }

    Tile(Color c) {
      color = c;
    }

    void swap_color() {
      if (color == Color::WHITE) {
        color = Color::BLACK;
      } else {
        color = Color::WHITE;
      }
    }
};

#endif
