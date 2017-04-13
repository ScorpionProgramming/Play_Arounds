#include "Cell.h"


Cell::Cell(void)
{
	this->x = 0;
	this->y = 0;
	this->button = true;
	this->left = true;
	this->right = true;
	this->top = true;
	this->visied = false;
}

Cell::Cell(int x, int y){
	this->x = x;
	this->y = y;
	this->button = true;
	this->left = true;
	this->right = true;
	this->top = true;
	this->visied = false;
}

Cell::~Cell(void){}

Cell Cell::operator=(Cell c){
	this->x = c.x;
	this->y = c.y;
	this->button = c.button;
	this->left = c.left;
	this->right = c.right;
	this->top = c.top;
	return (*this);
}

const std::string Cell::toString(){
	std::stringstream ss;
	ss << "" << this->x << " " << this->y << "\n"
	    << this->top << " " << this->right << " " << this->button << " " << this->left << "\n" 
		<< this->visied << "\n";
	return ss.str();
}