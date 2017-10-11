

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



int main(int argc, char *argv[]) { //./PA5 gridSize #doodlebugs #ant #time_steps seed pause

	if (argc > 7) {
		printf("Too many inputs\n");
		return 1;
	}
	//defaul values for command line arguments
	int gridSize = 10;
	int doodlebugs = 5;
	int ants = 10;
	int time_steps = 1000;
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

	srand(seed);

	grid Board(gridSize);

	Board = generateAnts(ants, Board, gridSize);

	// Board = generateDoodlebugs(doodlebugs, Board, gridSize);

	// Board.displayGrid();
	// //move all the doodlebugs
	// int count = 0;
	// for (int i = 0; i < gridSize; i++) {
	// 	for (int j = 0; j < gridSize; j++) {
	// 		if (Board.G[i][j] != NULL) {
	// 				count++;
	// 				printf("%i\n", count);
	// 			if (!Board.G[i][j]->isPrey()) {
	// 				Board = Board.G[i][j]->move(Board);
	// 				Board.G[i][j] = NULL;
	// 			}
	// 		}
	// 	}
	// }
	// printf("------------------------------------------------------------------\n");
	Board.displayGrid();
	//move all the ants
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if (Board.G[i][j] != NULL) {
				if (Board.G[i][j]->isPrey()) {
					Board = Board.G[i][j]->move(Board);
					Board.G[i][j] = NULL;
				}
			}
		}
	}

	Board.displayGrid();

	printf("------------------------------------------------------------------\n");




}
