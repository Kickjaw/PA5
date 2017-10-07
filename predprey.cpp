

#include <cstdio>
#include <cstdlib>
#include "classes.h"
#include <iostream>


int main(int argc, char *argv[]) { //./PA5 gridSize #ant #doodlebugs #time_steps seed pause

	if (argc > 7) {
		printf("Too many inputs\n");
		break;
	}


	int gridSize = atoi(argv[1]);
	int ants = atoi(argv[2]);
	int doodlebugs = atoi(argv[3]);
	int time_steps = atoi(argv[4]);
	int seed = atoi(argv[5]);
	int pause = atoi(argv[6]);

	printf("hi\n");


}