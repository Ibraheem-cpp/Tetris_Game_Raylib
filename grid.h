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
public:
	Grid();
	void initializeGrid();
	void printGrid() const;
	void DrawGrid() const;

	int getRows() const;
	int getCols() const;
	int getCellSize() const;

	~Grid();
};