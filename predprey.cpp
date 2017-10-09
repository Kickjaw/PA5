

#include <cstdio>
#include <cstdlib>
#include "classes.h"
#include <iostream>


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

	std::cout << gridSize << " " << doodlebugs << " " << ants << " " << time_steps << " " << seed << " " << pause <<"\n";


	grid G(gridSize);

	G.displayGrid();


}