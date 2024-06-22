#include <raylib.h>
#include "../include/grid.hpp"
#include "../include/constants.hpp"

void Grid::Draw() 
{
  for(size_t x = 0; x < rows; x++)
  {
    for(size_t y = 0; y < columns; y++)
    {
      Color color = cells[x][y] ? Constants::CELL_GREEN_COLOR : Constants::CELL_GRAY_COLOR; 
      DrawRectangle(y * cellSize, x * cellSize, cellSize - 1 , cellSize - 1, color);
    }
  }
}

void Grid::SetCellValue(int row, int column, int value)
{
  if(IsWithinBounds(row, column))
  {
    cells[row][column] = value;
  }
}

int Grid::GetCellValue(int row, int column)
{
  if(IsWithinBounds(row, column))
  {
    return cells[row][column];
  }
  return 0;
}

inline bool Grid::IsWithinBounds(int row, int column)
{
  if (row >= 0 && row < rows && column >= 0 && column < columns)
  {
    return true;
  }
  return false;
}

void Grid::FillGridWithRandomValues()
{
  for(size_t row = 0; row < rows; row++)
  {
    for(size_t column = 0; column < columns; column++)
    {
      int randomValue = GetRandomValue(0, 4);
      cells[row][column] = (randomValue == 4) ? 1 : 0;
    }
  }
}

void Grid::Clear()
{
  for(size_t row = 0; row < rows; row++)
  {
    for(size_t column = 0; column < columns; column++)
    {
      cells[row][column] = 0;
    }
  }
}

void Grid::ToggleCell(size_t row, size_t column)
{
 if(IsWithinBounds(row, column))
  {
    cells[row][column] = !cells[row][column];
  }
}
