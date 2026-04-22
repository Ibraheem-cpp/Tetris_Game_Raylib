#pragma once

#include "grid.h"
#include "block.h"
#include "tetrominos.h"
#include <vector>

class Game {
private:
	Grid grid;
	double lastUpdateTime = 0;
	Block currentBlock;
	Block nextBlock;
	std::vector<Block> blocks;
	bool GameOver = false;
	int score = 0;

	void RotateBlock();
	void lockBlock();
	bool blockFits();
	void reset();

	Sound gameOverSound;
	Sound rotateBlockSound;
	Sound completeRowSound;

public:
	Game();
	Music bgMusic;

	std::vector<Block> getAllBlocks();
	Block getRandomBlock();
	void Draw();
	void checkInput();
	bool isInBounds();
	bool eventTriggered(double interval);
	void checkCompletedRows();

	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	void drawNextBlock(int offsetX, int offsetY);

	int getGridRows() const;
	int getGridCols() const;
	int getGridCellSize() const;
	int getScore() const;

	bool isGameOver() const;

	~Game();
};