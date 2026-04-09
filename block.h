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
	std::vector<Color> colors = { DARKGRAY, BLUE, YELLOW, PINK, GREEN, ORANGE, PURPLE, RED };
public:
	Block();

	void Draw();
};
