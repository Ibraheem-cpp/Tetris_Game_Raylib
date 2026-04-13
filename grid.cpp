#include <iostream>
#include "grid.h"
#include "raylib.h"

using namespace std;

Grid::Grid() {
	this->cellSize = 30;
	this->numCols = 10;
	this->numRows = 20;
	initializeGrid();
}

void Grid::initializeGrid() {
	this->grid = new int* [this->numRows];
	for (int i = 0; i < this->numRows; i++) {
		this->grid[i] = new int[this->numCols];
	}

	for (int i = 0; i < this->numRows; i++) {
		for (int j = 0; j < this->numCols; j++) {
			this->grid[i][j] = 0;
		}
	}

}

void Grid::printGrid() const {
	for (int i = 0; i < this->numRows; i++) {
		for (int j = 0; j < this->numCols; j++) {
			cout << this->grid[i][j] << " ";
		}
		cout << endl;
	}
}

void Grid::DrawGrid() const {
	for (int i = 0; i < this->numRows; i++) {
		for (int j = 0; j < this->numCols; j++) {
			int cellValue = this->grid[i][j];
			DrawRectangle(this->cellSize * j +1, this->cellSize * i + 1, this->cellSize - 1, this->cellSize - 1, this->colors[cellValue]);
		}
	}
}

bool Grid::isOutOfBounds(int row, int col) {
	if (row >= 0 && row < this->numRows && col >= 0 && col < this->numCols) {
		return false;
	}
	return true;
}

void Grid::changeGridCellsColor(int row, int col, int id) {
	grid[row][col] = id;
}

bool Grid::isCellEmpty(int row, int col) const {
	if (grid[row][col] == 0) {
		return true;
	}
	return false;
}

bool Grid::isRowFull(int row) const {
	for (int col = 0; col < this->numCols; col++) {
		if (grid[row][col] == 0) {
			return false;
		}
	}
	return true;
}

int Grid::emptyCompletedRows() {
	int count = 0;
	for (int row = this->numRows - 1; row >= 0; row--) {
		if (isRowFull(row)) {
			count++;
			emptyCurrentRow(row);
			moveAllRowsDown(row);
			row++;
		}
	}

	return count;
}

void Grid::moveAllRowsDown(int row) {
	for (int r = row; r > 0; r--) {
		for (int c = 0; c < this->numCols; c++) {
			grid[r][c] = grid[r - 1][c];
		}
	}
}

void Grid::emptyCurrentRow(int row) {
	for (int col = 0; col < this->numCols; col++) {
		grid[row][col] = 0;
	}
}

int Grid::getRows() const {
	return this->numRows;
}

int Grid::getCols() const {
	return this->numCols;
}

int Grid::getCellSize() const {
	return this->cellSize;
}

void Grid::resetBoard() {
	for (int row = 0; row < this->numRows; row++) {
		for (int col = 0; col < this->numCols; col++) {
			grid[row][col] = 0;
		}
	}
}

Grid::~Grid() {
	for (int i = 0; i < this->numRows; i++) {
		delete[] this->grid[i];
		this->grid[i] = nullptr;
	}

	delete[] this->grid;
	this->grid = nullptr;
}