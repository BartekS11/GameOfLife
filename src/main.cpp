#include <cstdio>
#include <raylib.h>
#include "../include/simulation.hpp"
#include "../include/constants.hpp"

int main() {
  char title[128] = "GameOfLife";
  int FPS_temp = 12;
  InitWindow(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, title);
  // SetTargetFPS(Constants::FPS);
  SetTargetFPS(FPS_temp);

  Simulation simulation = { Constants::CELL_SIZE, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT };

  while(!WindowShouldClose())
  {
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
      Vector2 mousePos = GetMousePosition();
      int mouseRow = mousePos.y / Constants::CELL_SIZE;
      int mouseColumn = mousePos.x / Constants::CELL_SIZE;
      simulation.ToggleGridCell(mouseRow, mouseColumn);
    }

    if(IsKeyPressed(KEY_ENTER))
    {
      simulation.SimulationStartStop();
    }
    std::snprintf(title, sizeof(title), "Game of Life | %.0d", GetFPS());
    SetWindowTitle(title);

    if(IsKeyPressed(KEY_W))
    {
      if(FPS_temp > 5)
      {
        FPS_temp += 2;
        SetTargetFPS(FPS_temp);
      }
    }
    else if(IsKeyPressed(KEY_S))
    {
      if(FPS_temp > 5)
      {
        FPS_temp -= 2;
        SetTargetFPS(FPS_temp);
      }
    }
    else if(IsKeyPressed(KEY_R))
    {
      simulation.CreateRandomState();
    }
    else if(IsKeyPressed(KEY_C))
    {
      simulation.ClearGrid();
    }

    simulation.Update();

    BeginDrawing();
    ClearBackground(Constants::BG_GRAY_COLOR);
    simulation.Draw();

    EndDrawing();
  }
  CloseWindow();
}

