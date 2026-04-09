#include "tetrominos.h"
#include "Position.h"

L_Tetromino::L_Tetromino() {
	this->id = 1;
	this->cells[0] = { Position(1,0), Position(1,1), Position(1,2), Position(0,2) };
	this->cells[1] = { Position(0,1), Position(1,1), Position(2,1), Position(2,2) };
	this->cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,0) };
	this->cells[3] = { Position(0,0), Position(0,1), Position(1,1), Position(2,1) };
}