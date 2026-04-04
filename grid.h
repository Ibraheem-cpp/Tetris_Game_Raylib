#pragma once

class Grid {
private:
	int numRows = 0;
	int numCols = 0;
	int cellSize = 0;
	int** grid;
public:
	Grid();
	void initializeGrid();
	void printGrid() const;

	int getRows() const;
	int getCols() const;
	int getCellSize() const;

	~Grid();
};