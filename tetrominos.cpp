#include "tetrominos.h"
#include "Position.h"

L_Tetromino::L_Tetromino() {
	this->id = 1;
	this->cells[0] = { Position(1,0), Position(1,1), Position(1,2), Position(0,2) };
	this->cells[1] = { Position(0,1), Position(1,1), Position(2,1), Position(2,2) };
	this->cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,0) };
	this->cells[3] = { Position(0,0), Position(0,1), Position(1,1), Position(2,1) };
	move(0, 3);
}


J_Tetromino::J_Tetromino() {
	this->id = 2;
	this->cells[0] = { Position(0,0), Position(1,0), Position(1,1), Position(1,2) };
	this->cells[1] = { Position(0,1), Position(0,2), Position(1,1), Position(2,1) };
	this->cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,2) };
	this->cells[3] = { Position(0,1), Position(1,1), Position(2,0), Position(2,1) };
	move(0, 3);
}


I_Tetromino::I_Tetromino() {
	this->id = 3;
	this->cells[0] = { Position(1,0), Position(1,1), Position(1,2), Position(1,3) };
	this->cells[1] = { Position(0,2), Position(1,2), Position(2,2), Position(3,2) };
	this->cells[2] = { Position(2,0), Position(2,1), Position(2,2), Position(2,3) };
	this->cells[3] = { Position(0,1), Position(1,1), Position(2,1), Position(3,1) };
	move(-1, 3);
}


O_Tetromino::O_Tetromino() {
	this->id = 4;
	this->cells[0] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
	move(0, 4);
}


S_Tetromino::S_Tetromino() {
	this->id = 5;
	this->cells[0] = { Position(0,1), Position(0,2), Position(1,0), Position(1,1) };
	this->cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,2) };
	this->cells[2] = { Position(1,1), Position(1,2), Position(2,0), Position(2,1) };
	this->cells[3] = { Position(0,0), Position(1,0), Position(1,1), Position(2,1) };
	move(0, 3);
}


T_Tetromino::T_Tetromino() {
	this->id = 6;
	this->cells[0] = { Position(0,1), Position(1,0), Position(1,1), Position(1,2) };
	this->cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,1) };
	this->cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,1) };
	this->cells[3] = { Position(0,1), Position(1,0), Position(1,1), Position(2,1) };
	move(0, 3);
}


Z_Tetromino::Z_Tetromino() {
	this->id = 7;
	this->cells[0] = { Position(0,0), Position(0,1), Position(1,1), Position(1,2) };
	this->cells[1] = { Position(0,2), Position(1,1), Position(1,2), Position(2,1) };
	this->cells[2] = { Position(1,0), Position(1,1), Position(2,1), Position(2,2) };
	this->cells[3] = { Position(0,1), Position(1,0), Position(1,1), Position(2,0) };
	move(0, 3);
}