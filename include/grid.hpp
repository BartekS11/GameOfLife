#pragma once
#include <cstddef>
#include <memory>
#include <sys/types.h>
#include <vector>

class Grid
{
  public:
    Grid(int cellSize, int width, int height) 
      : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)),
      cells_test(new bool[width * height], width, height) {}
    void Draw();
    void SetCellValue(int row, int column, int value);
    int GetCellValue(int row, int column);
    int GetGridRows() const { return rows; }
    int GetGridColumns() const { return columns; }
    void FillGridWithRandomValues();
    void Clear();
    void ToggleCell(size_t row, size_t column);

  private:
    size_t rows = 0;
    size_t columns = 0;
    size_t cellSize = 0;
    std::vector<std::vector<int>> cells;

   //TEST
    std::tuple<std::shared_ptr<bool[]>, int, int> cells_test;
  
  private:
    bool IsWithinBounds(int row, int column);
};
