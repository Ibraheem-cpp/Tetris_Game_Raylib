#pragma once

#include "grid.h"
#include "block.h"
#include "tetrominos.h"
#include <vector>

class Game {
private:
	Grid grid;
	Block currentBlock;
	Block nextBlock;
	std::vector<Block> blocks;

public:
	Game();

	std::vector<Block> getAllBlocks();
	Block getRandomBlock();
	void Draw();
	int getGridRows() const;
	int getGridCols() const;
	int getGridCellSize() const;
};