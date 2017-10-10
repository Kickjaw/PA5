#include <cstdio>
#include <cstdlib>
#include "classes.h"
#include <iostream>


organism::organism() {
	lifeSpan = 0;
	x_loc = 0;
	y_loc = 0;
	breedCount = 0;
	prey = true;
}

doodlebug::doodlebug() {
	lifeSpan = 0;
	x_loc = 0;
	y_loc = 0;
	breedCount = 0;
	prey = false;
}


organism::~organism() {

};


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
//organism methods
//----------------------------------------------------------------------------------------------------
int organism::whatAmI(void) {
	return 0;
}

void organism::move(grid G){};

void organism::breed(grid G){};

void organism::getStarvation(void){};

void organism::eat(void){};

bool organism::isPrey(void) {
	return prey;
}






//ant methods
//-----------------------------------------------------------------------------------------------------

int ant::whatAmI(void) {
	return 1;
}

void ant::move(grid G){
	int direction;
	int options = 0;
	int optionsArray[4];
	printf("hello\n");

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
	printf("hi\n");
	ant *temp = new ant();
	temp -> lifeSpan = lifeSpan + 1;
	temp -> breedCount = breedCount + 1;
	temp -> x_loc = x_loc;
	temp -> y_loc = y_loc;

	switch(direction) {
		case(1): //move up
			temp -> y_loc = y_loc-1;
		case(2): //move down
			temp -> y_loc = y_loc+1;
		case(3): //moce left
			temp -> x_loc = x_loc-1;
		case(4):
			temp -> x_loc = x_loc+1;
	printf("hi\n");
	G.G[temp->y_loc][temp->x_loc] = temp; //move the bug to the new cell
	G.G[y_loc][x_loc] = NULL;//set old cell to null, may need to do this outside this function.

	}
}

void ant::breed(grid G){};

//doodlebug methods
//------------------------------------------------------------------------------------------------------

int doodlebug::whatAmI(void) {
	return 2;
}
 void doodlebug::move(grid G){
// 	int direction;
// 	int eatDirection;
// 	int options = 0;
// 	int optionsArray[4];
// 	int eatOptionsArray[4];
// 	bool eat = false;

// 	if (!G.checkUp(y_loc, x_loc)) {//checks if the cell is occupied
// 		if (G.G[y_loc][x_loc].whatAmI() == 1) { //checks if is an ant
// 			eatOptionsArray[options] = 1; //adds eat up option
// 			options = options + 1;
// 			eat = true;
// 	}
// 	if (!G.checkUp(y_loc, x_loc)) {//checks if the cell is occupied
// 		if (G.G[y_loc][x_loc].whatAmI() == 1) { //checks if is an ant
// 			eatOptionsArray[options] = 2; //adds eat down option
// 			options = options + 1;
// 			eat = true;
// 	}
// 	if (!G.checkUp(y_loc, x_loc)) {//checks if the cell is occupied
// 		if (G.G[y_loc][x_loc].whatAmI() == 1) { //checks if is an ant
// 			eatOptionsArray[options] = 3; //adds eat left option
// 			options = options + 1;
// 			eat = true;
// 	}
// 	if (!G.checkUp(y_loc, x_loc)) {//checks if the cell is occupied
// 		if (G.G[y_loc][x_loc].whatAmI() == 1) { //checks if is an ant
// 			eatOptionsArray[options] = 4; //adds eat right option
// 			options = options + 1;
// 			eat = true;
// 	}
// 	if (eat) {
// 		eatDirection = optionsArray[rand() % options]; //randomly choose one of the eat options

// 		switch(eatDirection) {
// 			case 1:
// 			case 2:
// 			case 3:
// 			case 4:
 		}

// 	if (!eat) {
// 		if (G.checkUp(y_loc, x_loc)) {//checks if the cell is open
// 			optionsArray[options] = 1; //add up option to option array
// 			options = options + 1;

// 		}
// 		if (G.checkDown(y_loc, x_loc)) {//checks if the cell is open
// 			optionsArray[options] = 2; // add down option to option array
// 			options = options + 1;
// 		}
// 		if (G.checkLeft(y_loc, x_loc)) {//checks if the cell is open
// 			optionsArray[options] = 3; //add left option to option array
// 			options = options + 1;
// 		}
// 		if (G.checkRight(y_loc, x_loc)) {//checks if the cell is open
// 			optionsArray[options] = 4; // add right option to opt
// 			options = options + 1;
// 		}


// 		direction = optionsArray[rand() % options];

// 		switch(direction) {
// 			case 1: //move up
// 				G.G[y_loc][x_loc] = NULL
// 				y_loc = y_loc-1;
// 				G.G[y_loc][x_loc] = new doodlebug();
// 				G.G[y_loc][x_loc] -> lifeSpan
// 				//change the stats
// 			case 2: //move down
// 				y_loc = y_loc+1;
// 			case 3: //moce left
// 				x_loc = x_loc-1;
// 			case 5:
// 				x_loc = x_loc+1;

// 		}
// 	}
// }
void doodlebug::breed(grid G){
	int options = 0;
	int direction;
	int breedOptionsArray[4];

	if (breedCount >= 8) {
		if (G.checkUp(y_loc, x_loc)) {
			breedOptionsArray[options] = 1; //add up option to option array
			options = options + 1;
		}
		if (G.checkDown(y_loc, x_loc)) {
			breedOptionsArray[options] = 2; // add down option to option array
			options = options + 1;
		}
		if (G.checkLeft(y_loc, x_loc)) {
			breedOptionsArray[options] = 3; //add left option to option array
			options = options + 1;
		}
		if (G.checkRight(y_loc, x_loc)) {
			breedOptionsArray[options] = 4; // add right option to opt
			options = options + 1;
		}

		direction = breedOptionsArray[rand() % options];

		switch(direction) {
			case 1:
				//add doodlebug up
				G.G[y_loc][x_loc] = new doodlebug();
			case 2:
				//add doodlebug down
				break;
			case 3:
				//add doodlebug left
				break;
			case 4:
				//add doodlebug right
				break;
		}
	}
}


void doodlebug::getStarvation(void){};

//grid methods
//---------------------------------------------------------------------------------------------
void grid::insertBug(int x, int y, int bugType) {
	if (bugType == 1) {
		ant *A = new ant();
		A -> x_loc = x;
		A -> y_loc = y;
		G[x][y] = A;
	}
	else if (bugType == 2) {
		doodlebug *A = new doodlebug();
		A -> x_loc = x;
		A -> y_loc = y;
		G[x][y] = A;
	}
}

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



