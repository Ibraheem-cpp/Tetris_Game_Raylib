#pragma once

class Position {
private:
	int row = 0;
	int column = 0;
public:
	Position();
	Position(int row, int column);

	int getRow();
	int getColumn();
};
