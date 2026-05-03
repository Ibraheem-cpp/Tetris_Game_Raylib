#pragma once
#include "raylib.h"
#include <vector>

class Grid {
private:
	int numRows = 0;
	int numCols = 0;
	int cellSize = 0;
	int** grid;
	std::vector<Color> colors = { BLACK, BLUE, YELLOW, PINK, GREEN, ORANGE, PURPLE, RED };

	bool isRowFull(int row) const;
	void moveAllRowsDown(int row);
	void emptyCurrentRow(int row);

public: 
	Grid();
	void initializeGrid();
	void printGrid() const;
	void DrawGrid() const;
	bool isOutOfBounds(int row, int col) const;
	void changeGridCellsColor(int row, int col, int id);
	bool isCellEmpty(int row, int col) const;
	int emptyCompletedRows();
	
	int getRows() const;
	int getCols() const;
	int getCellSize() const;

	void resetBoard();

	~Grid();
};