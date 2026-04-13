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

bool Game::eventTriggered(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime > interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
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
		MoveBlockLeft();
	}
	if (IsKeyPressed(KEY_S)) {
		MoveBlockDown();
	}
	if (IsKeyPressed(KEY_D)) {
		MoveBlockRight();
	}
	if (IsKeyPressed(KEY_W)) {
		RotateBlock();
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

void Game::MoveBlockLeft() {
	this->currentBlock.moveLeft();
	if ((!isInBounds()) || (!blockFits())) {
		this->currentBlock.move(0, 1);
	}
}

void Game::MoveBlockDown() {
	this->currentBlock.moveDown();
	if ((!isInBounds()) || (!blockFits())) {
		this->currentBlock.move(-1, 0);
		lockBlock();
	}
}

void Game::MoveBlockRight() {
	this->currentBlock.moveRight();
	if ((!isInBounds()) || (!blockFits())) {
		this->currentBlock.move(0, -1);
	}
}

void Game::RotateBlock () {
	this->currentBlock.changeRotationState();
	if ((!isInBounds()) || (!blockFits())) {
		this->currentBlock.undoRotation();
	}
}

bool Game::blockFits() {
	std::vector<Position> tiles = this->currentBlock.getCellPositions();
	for (Position items : tiles) {
		if (!grid.isCellEmpty(items.getRow(), items.getColumn())) {
			return false;
		}
	}

	return true;
}

void Game::lockBlock() {
	std::vector<Position> tiles = currentBlock.getCellPositions();
	int colorID = this->currentBlock.getColorID();
	
	for (Position items : tiles) {
		grid.changeGridCellsColor(items.getRow(), items.getColumn(), colorID);
	}

	currentBlock = nextBlock;
	nextBlock = getRandomBlock();
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