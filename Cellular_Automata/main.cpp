#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>

#include "RGBImage.h"
#include "Color.h"

/*
http://natureofcode.com/book/chapter-7-cellular-automata/
*/

unsigned int rule(unsigned int a, unsigned int b, unsigned int c, unsigned int ruleset[]){
	if		(a == 0 && b == 0 && c == 0){
		return ruleset[0];
	}else if(a == 0 && b == 0 && c == 1){
		return ruleset[1];
	}else if(a == 0 && b == 1 && c == 0){
		return ruleset[2];
	}else if(a == 0 && b == 1 && c == 1){
		return ruleset[3];
	}else if(a == 1 && b == 0 && c == 0){
		return ruleset[4];
	}else if(a == 1 && b == 0 && c == 1){
		return ruleset[5];
	}else if(a == 1 && b == 1 && c == 0){
		return ruleset[6];
	}else if(a == 1 && b == 1 && c == 1){
		return ruleset[7];
	}else{
		return ruleset[0];
	}
}

 unsigned int* generate(unsigned int* data, unsigned int width, unsigned int height, unsigned int* ruleset){
	srand (time(NULL));
	data = new unsigned int[width * height];

	for(int i = 0; i < 8; i++){
		ruleset[i] = rand() % 2;
	}

	for(unsigned int y = 0; y < height; y++){
		for(unsigned int x = 0; x <= width; x++){
			if(y == 0) {
				//data[x + y * _height] = rand() % 2;
				if(x % (width/2) == 0 && x != 0){
					data[x + y * height] = 1;
				}else{
					data[x + y * height] = 0;
				}
			}else{
				if(x == 0 || x == width-1 || y == 0 ){
					data[x + y * width] = 0;
				}else{
					data[x + y * width] = rule(data[(x - 1) + (y - 1) * width], data[x + (y - 1) * width], data[(x + 1) + (y - 1) * width], ruleset);
				}
			}
		}
	}

	return data;
}


int main(){
	//unsigned int ruleset[] = {0,1,0,1,1,0,1,0};

	unsigned int ruleset[8];

	unsigned int _width, _height;

	_width = 512; 
	_height = 512;

	RGBImage image = RGBImage(_width, _height);

	for(int h = 0; h < 256; h++){

		unsigned int* data = 0;

		data = generate(data, _width, _height, ruleset);

		//dateiname:
		std::stringstream ss;
		ss << "images/";
		//ss << "/images/";
		for(int i = 0; i < 8; i++){
			std::cout << ruleset[i] << " ";
			ss << ruleset[i];
		}
		ss << ".bmp";
		std::cout << "\n";

		//bild erstellen:
		

		for(unsigned int i = 0; i < _width * _height; i++){
			if(data[i] == 1){
				//std::cout << '#' ; 
				image.setPixelColor((i % _width),(i / _width),Color(1,1,1));
			}else{
				//std::cout << ' ';
				image.setPixelColor((i % _width),(i / _width),Color(0, 0, 0));

			}
			if(i % _width == _width - 1){
				//std::cout << std::endl;
				//_sleep(50);
			}
		}

		image.saveToDisk(ss.str().c_str());
	}

	delete &image;
	system("Pause");
	return 0;
}