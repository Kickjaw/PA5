

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
	int gridSize = 20;
	int doodlebugs = 5;
	int ants = 100;
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

	bool termination = false;
	int stepCount = 0;
	int antsRemain = 0;
	int doodlebugRemain = 0;

	srand(seed); //seed the random function

	grid Board(gridSize); // create board

	Board = generateAnts(ants, Board, gridSize); 

	Board = generateDoodlebugs(doodlebugs, Board, gridSize);

	Board.displayGrid();

	printf("------------------------------------------------------------------\n");

	while ((stepCount<time_steps) && (!termination)) {
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
		//move all the ants
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				if (Board.G[i][j] != NULL) {
					if (Board.G[i][j]->isPrey()) {
						if (!Board.G[i][j]->moved){
							Board = Board.G[i][j]->move(Board);
							Board.G[i][j] = NULL; //remove the bug from its starting location
						}
					}
				}
			}
		}
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

		//breed ants and doodlebugs
		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				if (Board.G[i][j] != NULL) {
					Board = Board.G[i][j]->breed(Board);
				}
			}
		}

		Board.displayGrid();

		resetMove(Board); //reset set the move boolean of the organisms

		printf("------------------------------------------------------------------\n");

		stepCount++;
		termination = true; //sets termination to true

		for (int i = 0; i < gridSize; i++) {
			for (int j = 0; j < gridSize; j++) {
				if (Board.G[i][j] != NULL) {
					termination = false; //if there is anything on the board it then sets it back to false
				}
			}
		}


		if (pause > 0) { //puase the sim until key press
			printf("Press enter to contiue");
			getchar();
		}

		

	} 
	//counts the remaing bugs on the board
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if (Board.G[i][j] != NULL) {
				if (Board.G[i][j] -> isPrey ()) {
					antsRemain++;
				}
				else {
					doodlebugRemain++;
				}
			}
		}
	}


	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Total steps: " << stepCount << std::endl;
	std::cout << "Total ants: " << Board.totalAnts << " Ants remaining: "<< antsRemain << std::endl;
	std::cout << "Total doodlebugs: " << Board.totalDoodleBugs << " Doodlebugs remaining: " << doodlebugRemain << std::endl;
	Board.displayGrid();

}
