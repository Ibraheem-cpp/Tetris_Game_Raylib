#pragma once

#include<vector>
#include<map>
#include "position.h"
#include "raylib.h"

class Block {
private:
	int rotationState;
	int cellSize;
protected:
	int id;
	std::map<int, std::vector<Position>> cells;
	std::vector<Color> colors = { BLACK, BLUE, YELLOW, PINK, GREEN, ORANGE, PURPLE, RED };
	int rowOffset = 0;
	int columnOffset = 0;
public:
	Block();

	void Draw();
	std::vector<Position> getCellPositions();
	void move(int row, int col);
};
