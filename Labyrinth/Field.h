#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>
#include "Cell.h"

class Field
{
public:
	Field(void);
	Field(int width, int height);
	~Field(void);

	void displayMaze();
	void generateMaze();
	std::string toString();
	int getNeighbours(int x, int y);
private: 
	int width;
	int height;
	Cell** cells;
	std::vector<Cell> stack;
};

