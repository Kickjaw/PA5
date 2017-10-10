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
	moved = false;
	starvation = 0;
}

doodlebug::doodlebug() {
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

grid organism::move(grid Board){return Board;};

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

grid ant::move(grid Board){
	int new_x = x_loc;
	int new_y = y_loc;
	int direction;
	int options = 0;
	int optionsArray[4];


	if (Board.checkUp(y_loc, x_loc)) {
		optionsArray[options] = 1; //add up option to option array
		options = options + 1;

	}
	if (Board.checkDown(y_loc, x_loc)) {
		optionsArray[options] = 2; // add down option to option array
		options = options + 1;
	}
	if (Board.checkLeft(y_loc, x_loc)) {
		optionsArray[options] = 3; //add left option to option array
		options = options + 1;
	}
	if (Board.checkRight(y_loc, x_loc)) {
		optionsArray[options] = 4; // add right option to opt
		options = options + 1;
	}

	if (options > 0) {
		moved = true;
		direction = optionsArray[rand() % options];
	}

	switch(direction) {
		case(1): //move up
			new_y = y_loc-1;
			break;
		case(2): //move down
			new_y = y_loc+1;
			break;
		case(3): //moce left
			new_x = x_loc-1;
			break;
		case(4):
			new_x = x_loc+1;
			break;
	}

	Board.insertBug(new_x, new_y, 1);
	Board.G[new_y][new_x] -> lifeSpan = Board.G[y_loc][x_loc] -> lifeSpan + 1;
	Board.G[new_y][new_x] -> breedCount = Board.G[y_loc][x_loc] -> breedCount + 1;
	Board.G[new_y][new_x] ->  moved = true;

	return Board;
}

void ant::breed(grid G){};

//doodlebug methods
//------------------------------------------------------------------------------------------------------

int doodlebug::whatAmI(void) {
	return 2;
}
grid doodlebug::move(grid Board){
	int direction;
	int eatDirection;
	int options = 0;
	int optionsArray[4];
	int eatOptionsArray[4];
	int new_x = x_loc;
	int new_y = y_loc;
	bool eat = false;
	printf("tried to move\n");
	if (!Board.checkUp(y_loc, x_loc)) {//checks if the cell is occupied
		printf("Check up, occupied\n");
		if (Board.G[y_loc][x_loc]->isPrey()) { //checks if is an ant
			printf("found prey\n");
			eatOptionsArray[options] = 1; //adds eat up option
			options = options + 1;
			eat = true;
		}
	}
	if (!Board.checkUp(y_loc, x_loc)) {//checks if the cell is occupied
		if (Board.G[y_loc][x_loc]->isPrey()) { //checks if is an ant
			eatOptionsArray[options] = 2; //adds eat down option
			options = options + 1;
			eat = true;
		}
	}
	if (!Board.checkUp(y_loc, x_loc)) {//checks if the cell is occupied
		if (Board.G[y_loc][x_loc]->isPrey()) { //checks if is an ant
			eatOptionsArray[options] = 3; //adds eat left option
			options = options + 1;
			eat = true;
		}
	}
	if (!Board.checkUp(y_loc, x_loc)) {//checks if the cell is occupied
		if (Board.G[y_loc][x_loc]->isPrey()) { //checks if is an ant
			eatOptionsArray[options] = 4; //adds eat right option
			options = options + 1;
			eat = true;
		}
	}
	if (eat) {

		eatDirection = eatOptionsArray[rand() % options]; //randomly choose one of the eat options

		switch(eatDirection) {
			case(1): //move up
				new_y = y_loc-1;
				break;
			case(2): //move down
				new_y = y_loc+1;
				break;
			case(3): //move left
				new_x = x_loc-1;
				break;
			case(4)://move right
				new_x = x_loc+1;
				break;
		}
		Board.G[new_y][new_x] = NULL;
		Board.insertBug(new_x, new_y, 2);
		Board.G[new_y][new_x] -> lifeSpan = Board.G[y_loc][x_loc] -> lifeSpan + 1;
		Board.G[new_y][new_x] -> breedCount = Board.G[y_loc][x_loc] -> breedCount + 1;
		Board.G[new_y][new_x] -> starvation = 0;
		Board.G[new_y][new_x] ->  moved = true;

	}
	else if (!eat) {
		if (Board.checkUp(y_loc, x_loc)) {
			optionsArray[options] = 1; //add up option to option array
			options = options + 1;
		}
		if (Board.checkDown(y_loc, x_loc)) {
			optionsArray[options] = 2; // add down option to option array
			options = options + 1;
		}
		if (Board.checkLeft(y_loc, x_loc)) {
			optionsArray[options] = 3; //add left option to option array
			options = options + 1;
		}
		if (Board.checkRight(y_loc, x_loc)) {
			optionsArray[options] = 4; // add right option to opt
			options = options + 1;
		}

		if (options > 0) {
			direction = optionsArray[rand() % options];
		}

		switch(direction) {
			case(1): //move up
				new_y = y_loc-1;
				break;
			case(2): //move down
				new_y = y_loc+1;
				break;
			case(3): //move left
				new_x = x_loc-1;
				break;
			case(4)://move right
				new_x = x_loc+1;
				break;
		}

		Board.insertBug(new_x, new_y, 2);
		Board.G[new_y][new_x] -> lifeSpan = Board.G[y_loc][x_loc] -> lifeSpan + 1;
		Board.G[new_y][new_x] -> breedCount = Board.G[y_loc][x_loc] -> breedCount + 1;
		Board.G[new_y][new_x] ->  moved = true;

	}

	return Board;
}

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
		G[y][x] = A;
	}
	else if (bugType == 2) {
		doodlebug *A = new doodlebug();
		A -> x_loc = x;
		A -> y_loc = y;
		G[y][x] = A;
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
		if (G[x_loc][y_loc-1] != NULL) {
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
		if (G[x_loc][y_loc+1] != NULL) {
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
		if (G[x_loc-1][y_loc] != NULL) {
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
		if (G[x_loc+1][y_loc] != NULL) {
			return false;
		}
		else {
			return true;
		}
	}
}



