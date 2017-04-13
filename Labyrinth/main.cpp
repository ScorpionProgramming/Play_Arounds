#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Field.h"


int main(void){
	unsigned int x = 0, y = 0;
	std::cout << "X eingeben:";
    std::cin >> x;
	std::cout << "Y eingeben:";
    std::cin >> y;

	Field f = Field(x, y);
	srand(time(NULL));

	f.generateMaze();
	f.displayMaze();
	system("Pause");
	return 0;
}