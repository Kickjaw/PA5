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
/**
 * helps print grid functions, diferenitiates the ants from doodlebugs
 */
int organism::whatAmI(void) {
	return 0;
}
/**
 * virtual function for move
 */
grid organism::move(grid Board){return Board;};

/**
 * virtual function for breed
 */
void organism::breed(grid G){};

/**
 * getter for starvation
 */
int organism::getStarvation(void){
	return 0;
};

/**
 * virtual fucntion for eat 
 */
void organism::eat(void){};

/**
 * getter for prey boolean
 */
bool organism::isPrey(void) {
	return prey;
}






//ant methods
//-----------------------------------------------------------------------------------------------------
/**
 * helps print grid functions, diferenitiates the ants from doodlebugs
 */
int ant::whatAmI(void) {
	return 1;
}

/**
 * @param Board the grid class that holds the 2d array of all the cells
 * takes in the board, check if the is an empty cell around the ant, and randomly chooses one if there is and moves
 * the ant to that location
 */
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

/**
 * @param Board the grid class that holds the 2d array of all the cells
 * Takes in the grid, checks if the ant has been alive for more then three turns, if so trys to add an ant in a random
 * location arouind the ant if there is an empty cells
 */
void ant::breed(grid Board){
	int options = 0;
	int direction;
	int breedOptionsArray[4];

	if (breedCount >= 3) {
		if (Board.checkUp(y_loc, x_loc)) {
			breedOptionsArray[options] = 1; //add up option to option array
			options = options + 1;
		}
		if (Board.checkDown(y_loc, x_loc)) {
			breedOptionsArray[options] = 2; // add down option to option array
			options = options + 1;
		}
		if (Board.checkLeft(y_loc, x_loc)) {
			breedOptionsArray[options] = 3; //add left option to option array
			options = options + 1;
		}
		if (Board.checkRight(y_loc, x_loc)) {
			breedOptionsArray[options] = 4; // add right option to opt
			options = options + 1;
		}

		direction = breedOptionsArray[rand() % options];

		switch(direction) {
			case 1://add ant up
				Board.G[y_loc-1][x_loc] = new ant();
			case 2://add ant down
				Board.G[y_loc+1][x_loc] = new ant();
			case 3://add ant left
				Board.G[y_loc][x_loc-1] = new ant();
			case 4://and ant right
				Board.G[y_loc][x_loc+1] = new ant();

		}

	}

}

/**
 * getter for prey boolean
 */
bool ant::isPrey(void) {
	return prey;
}

//doodlebug methods
//------------------------------------------------------------------------------------------------------

/**
 * helps print grid functions, diferenitiates the ants from doodlebugs
 */
int doodlebug::whatAmI(void) {
	return 2;
}

/**
 * @param Board the grid class that holds the 2d array of all the cells
 * First checks the surrounding 4 cells to see if there is 1 or more ants, if yes it will randomly eat one of those
 * ants, if not it moves like the an ant
 */
grid doodlebug::move(grid Board){
	int direction;
	int eatDirection;
	int options = 0;
	int optionsArray[4];
	int eatOptionsArray[4];
	int new_x = x_loc;
	int new_y = y_loc;
	bool eat = false;

	if (!Board.checkUp(y_loc, x_loc) && (y_loc!=0)) {//checks if the cell is occupied
		if (Board.G[y_loc-1][x_loc]->isPrey()) { //checks if is an ant
			eatOptionsArray[options] = 1; //adds eat up option
			options = options + 1;
			eat = true;
		}
	}
	if (!Board.checkDown(y_loc, x_loc) && (y_loc!=Board.gridSize-1)) {//checks if the cell is occupied
		if (Board.G[y_loc+1][x_loc]->isPrey()) { //checks if is an ant
			eatOptionsArray[options] = 2; //adds eat down option
			options = options + 1;
			eat = true;
		}
	}
	if (!Board.checkLeft(y_loc, x_loc) && (x_loc!=0)) {//checks if the cell is occupied
		if (Board.G[y_loc][x_loc-1]->isPrey()) { //checks if is an ant
			eatOptionsArray[options] = 3; //adds eat left option
			options = options + 1;
			eat = true;
		}
	}
	if (!Board.checkRight(y_loc, x_loc) && (x_loc!=Board.gridSize-1)) {//checks if the cell is occupied
		if (Board.G[y_loc][x_loc+1]->isPrey()) { //checks if is an ant
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

/**
 * @param Board the grid class that holds the 2d array of all the cells
 * Takes in the grid, checks if the doodlebug has been alive for more then 8 turns, if so trys to add an ant in a random
 * location arouind the ant if there is an empty cells
 */
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

/**
 * getter for starvation
 */
int doodlebug::getStarvation(void){
	return starvation;
};

/**
 * getter for prey boolean
 */
bool doodlebug::isPrey(void) {
	return prey;
}

//grid methods
//---------------------------------------------------------------------------------------------
/**
 * @param x x location to insert the but in
 * @param y y location to insert the bug in
 * @param bugtype type of bug to insert in the board
 * takes in the locatino and the bugtype and inserts a new bug of that type in the board and the given location
 */
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

/**
 * prints out the whole board formated
 */
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
					printf("/");
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
 * takes in x and y location and checks if the cell the direction it and returns true if free and false if not
 */
bool grid::checkUp(int y_loc, int x_loc) {
	if (y_loc == 0) {
		return false;
	}
	else {
		if (G[y_loc-1][x_loc] != NULL) {
			return false;
		}
		else{
			return true;
		}
	}
}

/**
 * takes in x and y location and checks if the cell the direction it and returns true if free and false if not
 */
bool grid::checkDown(int y_loc, int x_loc) {
	if (y_loc == gridSize-1) {
		return false;
	}
	else {
		if (G[y_loc+1][x_loc] != NULL) {
			return false;
		}
		else {
			return true;
		}
	}

}

/**
 * takes in x and y location and checks if the cell the direction it and returns true if free and false if not
 */
bool grid::checkLeft(int y_loc, int x_loc) {
	if (x_loc == 0) {
		return false;
	}
	else {
		if (G[y_loc][x_loc-1] != NULL) {
			return false;
		}
		else {
			return true;
		}
	}

}

/**
 * takes in x and y location and checks if the cell the direction it and returns true if free and false if not
 */
bool grid::checkRight(int y_loc, int x_loc) {
	if (x_loc == gridSize-1) {
		return false;
	}
	else {
		if (G[y_loc][x_loc+1] != NULL) {
			return false;
		}
		else {
			return true;
		}
	}
}



