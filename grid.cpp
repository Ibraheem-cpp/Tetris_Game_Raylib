#include <iostream>
#include "grid.h"

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


int Grid::getRows() const {
	return this->numRows;
}

int Grid::getCols() const {
	return this->numCols;
}

int Grid::getCellSize() const {
	return this->cellSize;
}

Grid::~Grid() {
	for (int i = 0; i < this->numRows; i++) {
		delete[] this->grid[i];
		this->grid[i] = nullptr;
	}

	delete[] this->grid;
}