#pragma once

#include<vector>
#include<map>
#include "position.h"
#include "raylib.h"

class Block {
private:
	int id;
	int rotationState;
protected:
	std::map<int, std::vector<Position>> cells;
	std::vector<Color> colors = { DARKGRAY, BLUE, YELLOW, PINK, GREEN, ORANGE, PURPLE, RED };
};
