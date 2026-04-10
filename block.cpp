#include <iostream>
#include <vector>
#include "position.h"
#include "block.h"
#include "raylib.h"

Block::Block() {
	this->id = 0;
	this->cellSize = 30;
	this->rotationState = 0;
}

void Block::Draw() {
	std::vector<Position> tiles = getCellPositions();
	for (Position item : tiles) {
		DrawRectangle(item.getColumn() * this->cellSize + 1, item.getRow() * this->cellSize + 1, this->cellSize - 1, this->cellSize - 1, this->colors[this->id]);
	}
}

std::vector<Position> Block::getCellPositions() {
	std::vector<Position> tiles = this->cells[this->rotationState];
	for (Position& item : tiles) {
		item.updatePosition(this->rowOffset, this->columnOffset);
	}

	return tiles;
}

void Block::move(int row, int col) {
	this->rowOffset += row;
	this->columnOffset += col;
}
