#pragma once
#include <string>
#include <sstream>
class Cell
{
	friend class Field;
public:
	Cell(void);
	Cell(int x, int y);
	~Cell(void);
	Cell operator=(Cell c);
	const std::string toString();
	
protected: 
	int x;
	int y;
	bool top, button, left, right;
	bool visied;
};

 