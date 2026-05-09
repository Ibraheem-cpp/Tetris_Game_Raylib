#pragma once

#include "grid.h"
#include "raylib.h"
#include "block.h"
#include "tetrominos.h"
#include "button.h"
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
	int highestScore = 0;

	void RotateBlock();
	void lockBlock();
	bool blockFits();
	void reset();
	void loadHighestScore();
	
	Sound gameOverSound;
	Sound rotateBlockSound;
	Sound completeRowSound;
	Texture2D menuBG;
	Button playButton;
	Button exitButton;

public:
	Game();
	Music bgMusic;

	std::vector<Block> getAllBlocks();
	Block getRandomBlock();
	void Draw();
	void drawMenu();
	void checkInput();
	bool isInBounds();
	bool eventTriggered(double interval);
	void checkCompletedRows();

	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	void drawNextBlock(int offsetX, int offsetY);
	void checkHighestScore();
	void loadAssets();

	int getGridRows() const;
	int getGridCols() const;
	int getGridCellSize() const;
	int getScore() const;
	int getHighestScore() const;

	bool isGameOver() const;
	bool isPlayButtonClicked();
	bool isExitButtonClicked();

	~Game();
};