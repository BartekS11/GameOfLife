#include "../include/simulation.hpp"

void Simulation::Draw()
{
  grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
  grid.SetCellValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
  int liveNeighbors = 0;
  std::vector<std::pair<int, int>> neighborsOffset = 
  {
    {-1, 0}, // above
    {1, 0}, // below
    {0, -1}, // left
    {0, 1}, // right
    {-1, 1}, // above right
    {-1, -1}, // above left
    {1, 1}, // below right
    {1, -1} // below left
  };

  for(const auto& offset : neighborsOffset)
  {
    int offsetRow = (row + offset.first + grid.GetGridRows()) % grid.GetGridRows();
    int offsetColumn = (column + offset.second + grid.GetGridColumns()) % grid.GetGridColumns();
    liveNeighbors += grid.GetCellValue(offsetRow, offsetColumn);
  }

  return liveNeighbors;
}

void Simulation::Update()
{
  if(!IsSimulationRunning())
  {
    return;
  }

  for(size_t row = 0; row < grid.GetGridRows(); row++)
  {
    for(size_t column = 0; column < grid.GetGridColumns(); column++)
    {
      int liveNeighbors = CountLiveNeighbors(row, column);
      int cellValue = grid.GetCellValue(row, column);

      if(cellValue == 1)
      {
        if(liveNeighbors > 3 || liveNeighbors < 2)
        {
          tempGrid.SetCellValue(row, column, 0);
        }
        else
        {
          tempGrid.SetCellValue(row, column, 1);
        }
      }
      else
      {
        if(liveNeighbors == 3)
        {
          tempGrid.SetCellValue(row, column, 1);
        }
        else 
        {
          tempGrid.SetCellValue(row, column, 0);
        }
      }
    }
  }
  grid = tempGrid;
}

void Simulation::ClearGrid()
{
  if(!IsSimulationRunning())
  {
    grid.Clear();
  }
}

void Simulation::CreateRandomState()
{
  if(!IsSimulationRunning())
  {
    grid.FillGridWithRandomValues();
  }
}

void Simulation::ToggleGridCell(int row, int column)
{
  if(!IsSimulationRunning())
  {
    grid.ToggleCell(row, column);
  }
}
