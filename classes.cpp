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
	G = new organism*[gridSize];
	if (G) for (int i = 0; i < gridSize; i++) {
		G[i] = NULL;
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

void organism::move(grid G){
	int direction;
	int options = 0;
	int optionsArray[4];


	if (G.checkUp(y_loc, x_loc)) {
		optionsArray[options] = 1; //add up option to option array
		options = options + 1;

	}
	if (G.checkDown(y_loc, x_loc)) {
		optionsArray[options] = 2;
		options = options + 1;
	}
	if (G.checkLeft(y_loc, x_loc)) {
		optionsArray[options] = 3; //add left option to option array
		options = options + 1;
	}
	if (G.checkRight(y_loc, x_loc)) {
		optionsArray[options] = 4;
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
		for (int j = 0; i < gridSize; i ++) {
			bug = G[j][i].whatAmI();
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
