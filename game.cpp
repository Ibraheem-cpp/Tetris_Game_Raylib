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
	GameOver = false;
	score = 0;

	InitAudioDevice();
	bgMusic = LoadMusicStream("sounds/background.mp3");
	gameOverSound = LoadSound("sounds/gameover.mp3");
	rotateBlockSound = LoadSound("sounds/rotateblock.mp3");
	completeRowSound = LoadSound("sounds/completerow.mp3");

	PlayMusicStream(bgMusic);
	SetMusicVolume(bgMusic, 0.4f);
	
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
	if (GameOver) {
		if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_D) || IsKeyPressed(KEY_W)) { 
			GameOver = false;
			reset(); 
		}
	}

	if (IsKeyPressed(KEY_A)) {
		MoveBlockLeft();
	}
	if (IsKeyPressed(KEY_S)) {
		MoveBlockDown();
		this->score++;
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
	if (!GameOver) {
		this->currentBlock.moveLeft();
		if ((!isInBounds()) || (!blockFits())) {
			this->currentBlock.move(0, 1);
		}
	}
}

void Game::MoveBlockDown() {
	if (!GameOver) {
		this->currentBlock.moveDown();
		if ((!isInBounds()) || (!blockFits())) {
			this->currentBlock.move(-1, 0);
			lockBlock();
		}
	}
}

void Game::MoveBlockRight() {
	if (!GameOver) {
		this->currentBlock.moveRight();
		if ((!isInBounds()) || (!blockFits())) {
			this->currentBlock.move(0, -1);
		}
	}
}

void Game::RotateBlock () {
	if (!GameOver) {
		this->currentBlock.changeRotationState();
		if ((!isInBounds()) || (!blockFits())) {
			this->currentBlock.undoRotation();
		}
		else {
			PlaySound(rotateBlockSound);
		}
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
	if (!blockFits()) {
		GameOver = true;
		PlaySound(gameOverSound);
	}
	nextBlock = getRandomBlock();
}

void Game::checkCompletedRows() {
	int completed_rows = grid.emptyCompletedRows();
	if (completed_rows > 0) {
		PlaySound(completeRowSound);
		this->score += completed_rows * 100;
	}
}

bool Game::isGameOver() const {
	return this->GameOver;
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

int Game::getScore() const {
	return this->score;
}

void Game::reset() {
	grid.resetBoard();
	this->score = 0;
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
	ResumeMusicStream(bgMusic);
}

Game::~Game() {
	UnloadMusicStream(bgMusic);
	UnloadSound(gameOverSound);
	UnloadSound(completeRowSound);
	UnloadSound(rotateBlockSound);
	CloseAudioDevice();
}