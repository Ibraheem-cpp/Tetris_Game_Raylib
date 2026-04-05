#pragma once
#include<vector>
#include "raylib.h"

class Block {
private:
	int id;
	int rotationState;
	std::vector<Color> colors = { DARKGRAY, BLUE, YELLOW, PINK, GREEN, ORANGE, PURPLE, RED };
};
