

#include <cstdio>
#include <cstdlib>
#include "classes.h"
#include <iostream>


grid generateAnts(int ants, grid Board, int gridSize) {
	int x, y;
	bool placed;
	for (int i = 0; i < ants; i++) {
		placed = false;
		while (!placed) { //runs this loop until the x,y coords are unocupied and places the pug in that spot
			x = rand() % gridSize;
			y = rand() % gridSize;
			if (Board.G[y][x] == NULL) {
				Board.insertBug(x, y, 1);
				placed = true;
			}
		}
	}

	return Board;
}

grid generateDoodlebugs(int doodlebugs, grid Board, int gridSize) {
	int x, y;
	bool placed;
	for (int i = 0; i < doodlebugs; i++) {
		placed = false;
		while (!placed) { //runs this loop until the x,y coords are unocupied and places the pug in that spot
			x = rand() % gridSize;
			y = rand() % gridSize;
			if (Board.G[y][x] == NULL) {
				Board.insertBug(x, y, 2);
				placed = true;
			}
		}
	}

	return Board;
}

void resetMove(grid Board) {
	for (int i = 0; i < Board.gridSize; i++) {
		for (int j = 0; j < Board.gridSize; j++) {
			if (Board.G[i][j] != NULL) {
				Board.G[i][j] -> moved = false;
			}
		}
	}
}


int main(int argc, char *argv[]) { //./PA5 gridSize #doodlebugs #ant #time_steps seed pause

	if (argc > 7) {
		printf("Too many inputs\n");
		return 1;
	}
	//defaul values for command line arguments
	int gridSize = 10;
	int doodlebugs = 5;
	int ants = 10;
	int time_steps = 100;
	int seed = 1;
	int pause = 0;

	//set everything to default and run switch case in revese with no break statments

	switch(argc) {
		case 7:
			pause = atoi(argv[6]);
		case 6:
			seed = atoi(argv[5]);
		case 5:
			time_steps = atoi(argv[4]);
		case 4:
			ants = atoi(argv[3]);
		case 3:
			doodlebugs = atoi(argv[2]);
		case 2:
			gridSize = atoi(argv[1]);
		case 1:
			break;
	}

	bool termination = false;
	int stepCount = 0;

	srand(seed);

	grid Board(gridSize);

	Board = generateAnts(ants, Board, gridSize);

	Board = generateDoodlebugs(doodlebugs, Board, gridSize);

	Board.displayGrid();

	printf("------------------------------------------------------------------\n");

	while ((stepCount<time_steps)) {
		printf("move doodlebugs\n");
		//move all the doodlebugs
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				if (Board.G[i][j] != NULL) {
					if (!Board.G[i][j]->isPrey()) {
						if (!Board.G[i][j]->moved){
							Board = Board.G[i][j]->move(Board);
							Board.G[i][j] = NULL;
						}
					}
				}
			}
		}
		printf("move ants\n");
		//move all the ants
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				if (Board.G[i][j] != NULL) {
					if (Board.G[i][j]->isPrey()) {
						if (!Board.G[i][j]->moved){
							Board = Board.G[i][j]->move(Board);
							Board.G[i][j] = NULL;
						}
					}
				}
			}
		}
		printf("check startvation\n");
		//check startvation
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				if (Board.G[i][j] != NULL) {
					if (!Board.G[i][j]->isPrey()){
						if (Board.G[i][j]->getStarvation() >= 3) {
							Board.G[i][j] = NULL;
						}
					}
				}
			}
		}





		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				if (Board.G[i][j] != NULL) {
					Board.G[i][j] -> breed(Board);
				}
			}
		}


		Board.displayGrid();

		resetMove(Board);

		printf("------------------------------------------------------------------\n");

		stepCount++;
	}



}
