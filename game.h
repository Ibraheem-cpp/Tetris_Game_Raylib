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

	void RotateBlock();
	void lockBlock();
	bool blockFits();

public:
	Game();

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

	int getGridRows() const;
	int getGridCols() const;
	int getGridCellSize() const;
};