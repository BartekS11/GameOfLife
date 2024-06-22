#pragma once
#include "grid.hpp"
#include <sys/types.h>

class Simulation 
{
  public:
    Simulation(int cellSize, int width, int height)
     : grid(cellSize, width, height), tempGrid(cellSize, width, height), isRunning(false) {}
    void Draw();
    void SetCellValue(int row, int column, int value);
    int CountLiveNeighbors(int row, int column);
    void Update();
    bool IsSimulationRunning() const { return isRunning; };
    void SimulationStart() { isRunning = true; }
    void SimulationStop() { isRunning = false; }
    void SimulationStartStop() { isRunning = !isRunning; }
    void ClearGrid();
    void CreateRandomState();
    void ToggleGridCell(int row, int column);

  private:
    Grid grid;
    Grid tempGrid;
    bool isRunning;

};
