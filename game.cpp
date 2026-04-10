#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "game.h"

Game::Game() {
	srand(time(0));
	this->blocks = getAllBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
}

std::vector<Block> Game::getAllBlocks() {
	return { I_Tetromino(), S_Tetromino(), T_Tetromino(), L_Tetromino(), J_Tetromino(), O_Tetromino(), Z_Tetromino() };
}

Block Game::getRandomBlock() {
	if (this->blocks.empty()) {
		this->blocks = getAllBlocks();
	}
	int ind = rand() % this->blocks.size();
	Block block = blocks[ind];
	blocks.erase(blocks.begin() + ind);
	return block;
}

void Game::Draw() {
	this->grid.DrawGrid();
	this->currentBlock.Draw();
}

void Game::checkInput() {
	if (IsKeyPressed(KEY_A)) {
		this->currentBlock.moveLeft();
		if (!isInBounds()) {
			this->currentBlock.move(0, 1);
		}
	}
	if (IsKeyPressed(KEY_S)) {
		this->currentBlock.moveDown();
		if (!isInBounds()) {
			this->currentBlock.move(-1, 0);
		}
	}
	if (IsKeyPressed(KEY_D)) {
		this->currentBlock.moveRight();
		if (!isInBounds()) {
			this->currentBlock.move(0, -1);
		}
	}
}

bool Game::isInBounds() {
	std::vector<Position> tiles = this->currentBlock.getCellPositions();
	for (Position items : tiles) {
		if (grid.isOutOfBounds(items.getRow(), items.getColumn())) {
			return false;
		}
	}
	return true;
}

int Game::getGridCellSize() const {
	return this->grid.getCellSize();
}

int Game::getGridRows() const {
	return this->grid.getRows();
}

int Game::getGridCols() const {
	return this->grid.getCols();
}