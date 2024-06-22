#pragma once
#include "raylib.h"

struct Constants
{
  static constexpr int FPS = 12;
  static constexpr int CELL_SIZE = 25;
  static constexpr int WINDOW_HEIGHT = 800, WINDOW_WIDTH = 800;
  static constexpr Color BG_GRAY_COLOR = {29, 29, 29, 255};
  static constexpr Color CELL_GREEN_COLOR {0, 255, 0, 255};
  static constexpr Color CELL_GRAY_COLOR {55, 55, 55, 255};
};

