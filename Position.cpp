#include <iostream>
#include "position.h"

Position::Position() {}

Position::Position(int row, int column) {
	this->row = row;
	this->column = column;
}

int Position::getRow() {
	return this->row;
}

int Position::getColumn() {
	return this->column;
}