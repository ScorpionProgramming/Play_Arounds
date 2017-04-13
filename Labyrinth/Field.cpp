#include "Field.h"
#include "Vector"

Field::Field(void)
{
	this->width = 25;
	this->height = this->width;

	cells = new Cell*[this->width];
	for(int i = 0; i < this->width; i++){
		cells[i] = new Cell[this->height];
	}

	Cell c;
	for(int j = 0; j < this->height; j++){
		for(int i = 0; i < this->width; i++){
			c = Cell(i, j);
			cells[i][j] = c;
		}
	}
}

Field::Field(int width, int height){
	this->width = width;
	this->height = height;

	cells = new Cell*[this->width];
	for(int i = 0; i < this->width; i++){
		cells[i] = new Cell[this->height];
	}

	Cell c;
	for(int j = 0; j < this->height; j++){
		for(int i = 0; i < this->width; i++){
			c = Cell(i, j);
			cells[i][j] = c;
		}
	}
}

Field::~Field(void)
{
}

void Field::displayMaze(){
	for(int i = 0; i < this->width; i++){
		std::cout << " _";
	}
	std::cout << "\n";

	for(int j = 0; j < this->height; j++){
		for(int i = 0; i < this->width; i++){
			if(cells[i][j].left){
				std::cout << "|";
			}else{
				std::cout << " ";
			}
			if(cells[i][j].button){
				std::cout << "_";
			}else{
				std::cout << " ";
			}
			if(i == width-1){
				std::cout << "|";
			}
		}
		std::cout << std::endl;
	}

	//std::cout << stack.size() << std::endl;
}

std::string Field::toString(){
	std::stringstream ss;
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			ss << "" << cells[i][j].toString() << "\n";
		}
	}
	return ss.str();
}

/*
1. Make the initial cell the current cell and mark it as visited
2. While there are unvisited cells
	1. If the current cell has any neighbours which have not been visited
		1. Choose randomly one of the unvisited neighbours
		2. Push the current cell to the stack
		3. Remove the wall between the current cell and the chosen cell
		4. Make the chosen cell the current cell and mark it as visited
	2. Else if stack is not empty
		1. Pop a cell from the stack
		2. Make it the current cell*/
void Field::generateMaze(){
	Cell *curCell;
	Cell *nextCell; //next or backwards cell
	bool unvisiedCells = true;
	//std::vector<Cell> stack; //ist nun public.
	curCell = &cells[0][rand() % 10]; //eine der oberen Zellen als startwert
	curCell->visied = true; //besucht machen

	int neighbour;
	while(unvisiedCells){
		neighbour = this->getNeighbours(curCell->x, curCell->y);
		if(neighbour != -1){
			if(neighbour == 1){ //norden
				nextCell = &cells[curCell->x][( curCell->y )-1];
				curCell->top = false;
				nextCell->button = false;
			}else if(neighbour == 2){ //osten
				nextCell = &cells[(curCell->x)+1][curCell->y];
				curCell->right = false;
				nextCell->left = false;
			}else if(neighbour == 3){ //sueden
				nextCell = &cells[curCell->x][(curCell->y) + 1];
				curCell->button = false;
				nextCell->top = false;
			}else if(neighbour == 4){ //westen
				nextCell = &cells[(curCell->x)-1][curCell->y];
				curCell->left = false;
				nextCell->right = false;
			}
			cells[curCell->x][curCell->y] = *curCell;
			stack.push_back(*curCell);
			curCell = nextCell;
			curCell->visied = true;
		}else if(stack.size() != 0){
			curCell = &stack.back();
			stack.pop_back();
		}else{
			unvisiedCells = false;
		}
		//system("CLS");
		//this->displayMaze();
	}
}
/*
	Sucht alle Nachbarn die man haben kann 
	und wählt die richtung aus in die gegangen werden soll.
	norden 1, osten 2, sueden 3, westen 4, keins -1
*/
int Field::getNeighbours(int x, int y){
	bool north = false, south = false, west = false, east = false; 
	if( x == 0 && y == 0){
		if(cells[x][y+1].visied == false){
			south = true;
		}
		if(cells[x+1][y].visied == false){
			east = true;
		}
	}else if( x == width-1 && y == height-1 ){
		if(cells[x][y-1].visied == false){
			north = true;
		}
		if(cells[x-1][y].visied == false){
			west = true;
		}
	}else if( x == width-1 && y == 0 ){
		if(cells[x][y+1].visied == false){
			south = true;
		}
		if(cells[x-1][y].visied == false){
			west = true;
		}
	}else if( x == 0 && y == height-1 ){
		if(cells[x+1][y].visied == false){
			east = true;
		}
		if(cells[x][y-1].visied == false){
			north = true;
		}
	}else if( x == 0 ) {
		if(cells[x][y+1].visied == false){
			south = true;
		}
		if(cells[x+1][y].visied == false){
			east = true;
		}
		if(cells[x][y-1].visied == false){
			north = true;
		}
	}else if( x == width-1 ){
		if(cells[x][y+1].visied == false){
			south = true;
		}
		if(cells[x][y-1].visied == false){
			north = true;
		}
		if(cells[x-1][y].visied == false){
			west = true;
		}
	}else if( y == 0 ){
		if(cells[x][y+1].visied == false){
			south = true;
		}
		if(cells[x+1][y].visied == false){
			east = true;
		}
		if(cells[x-1][y].visied == false){
			west = true;
		}
	}else if( y == height-1 ){
		if(cells[x+1][y].visied == false){
			east = true;
		}
		if(cells[x][y-1].visied == false){
			north = true;
		}
		if(cells[x-1][y].visied == false){
			west = true;
		}
	}else{
		if(cells[x][y+1].visied == false){
			south = true;
		}
		if(cells[x+1][y].visied == false){
			east = true;
		}
		if(cells[x][y-1].visied == false){
			north = true;
		}
		if(cells[x-1][y].visied == false){
			west = true;
		}
	}
	
	//richtungen hinzufuegen: 
	std::vector<int> richtungen;
	if(north)
		richtungen.push_back(1);
	if(east)
		richtungen.push_back(2);
	if(south)
		richtungen.push_back(3);
	if(west)
		richtungen.push_back(4);
	
	
	if(richtungen.size() == 0)
		return -1;

	int richtung = richtungen.at(rand() % richtungen.size());
	richtungen.clear();
	//zufaellige zahl aus dem richtungsarray auswäheln und zurückgeben
	return richtung;
}