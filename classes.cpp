#include <cstdio>
#include <cstdlib>
#include "classes.h"
#include <iostream>


organism::organism() {
	lifeSpan = 0;
	x_loc = 0;
	y_loc = 0;
	breedCount = 0;
}

grid::grid(int size) {
	gridSize = size;
	G = new organism**[gridSize]; // Indstantiate array of pointers to the row arrays.
	if (G) for (int i = 0; i < gridSize; i++) {
		G[i] = new  organism*[gridSize]; // Allocate the next row array
		for (int j = 0; j < gridSize; j++) {
			G[i][j] = NULL; // Each cell starts empty
		}
		if (!G[i]) exit(-1);
	}
	

}


int organism::whatAmI(void) {
	return 0;
}

int ant::whatAmI(void) {
	return 1;
}

int doodlebug::whatAmI(void) {
	return 2;
}


/**
 *
 */
void organism::move(grid G){
	int direction;
	int options = 0;
	int optionsArray[4];


	if (G.checkUp(y_loc, x_loc)) {
		optionsArray[options] = 1; //add up option to option array
		options = options + 1;

	}
	if (G.checkDown(y_loc, x_loc)) {
		optionsArray[options] = 2; // add down option to option array
		options = options + 1;
	}
	if (G.checkLeft(y_loc, x_loc)) {
		optionsArray[options] = 3; //add left option to option array
		options = options + 1;
	}
	if (G.checkRight(y_loc, x_loc)) {
		optionsArray[options] = 4; // add right option to opt
		options = options + 1;
	}


	direction = optionsArray[rand() % options];

	switch(direction) {
		case(1): //move up
			y_loc = y_loc-1;
		case(2): //move down
			y_loc = y_loc+1;
		case(3): //moce left
			x_loc = x_loc-1;
		case(4):
			x_loc = x_loc+1;

	}
}

void doodlebug::eat(void){};


void grid::displayGrid(void) {
	int bug;
	
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if (G[i][j] == NULL) {// if cell is empty G will evaulate to NULL
				bug = 0;
			}
			else {// else check for what cell contains
				bug = G[i][j]->whatAmI();
			}
			switch(bug){
				case 0:
					printf(" ");
					break;
				case 1:
					printf("O");
					break;
				case 2:
					printf("X");
					break;
				default:
					printf("something went wrong\n");
					break;
			}
		}
	printf("\n");
	}
}
/**
 * takes in x and y location and checks if the cell above it and returns true if free and false if not
 */
bool grid::checkUp(int y_loc, int x_loc) {
	if (y_loc == 0) {
		return false;
	}
	else {
		if (G[x_loc][y_loc] != NULL) {
			return false;
		}
		else{
			return true;
		}
	}
}

bool grid::checkDown(int y_loc, int x_loc) {
	if (y_loc == gridSize-1) {
		return false;
	}
	else {
		if (G[x_loc][y_loc] != NULL) {
			return false;
		}
		else {
			return true;
		}
	}

}

bool grid::checkLeft(int y_loc, int x_loc) {
	if (x_loc == 0) {
		return false;
	}
	else {
		if (G[x_loc][y_loc] != NULL) {
			return false;
		}
		else {
			return true;
		}
	}

}

bool grid::checkRight(int y_loc, int x_loc) {
	if (x_loc == gridSize-1) {
		return false;
	}
	else {
		if (G[x_loc][y_loc] != NULL) {
			return false;
		}
		else {
			return true;
		}
	}
}

void doodlebug::breed(void){};
void organism::getStarvation(void){};
void doodlebug::getStarvation(void){};
void organism::breed(void){};
void organism::eat(void){};