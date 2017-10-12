#ifndef CLASSES_H 
#define CLASSES_H

#include <cstdio>
#include <cstdlib>

class organism;

class grid {
public:
	int gridSize;
	int antsInBoard;
	int totalAnts;
	int doodlebugsInBoard;
	int totalDoodleBugs;
	organism ***G;

	grid(int size);

	void insertBug(int x, int y, int bugType);
	void displayGrid(void);
	bool checkUp(int y_loc, int x_loc);
	bool checkDown(int y_loc, int x_loc);
	bool checkLeft(int y_loc, int x_loc);
	bool checkRight(int y_loc, int x_loc);

};

class organism {
public:

	int lifeSpan;
	int x_loc;
	int y_loc;
	int breedCount;
	bool prey;
	bool moved; //value to check if the bug has moved this step
	int starvation;

	organism();
	virtual ~organism();

	virtual int whatAmI(void);
	virtual grid move(grid Board);
	virtual grid breed(grid G);
	virtual int getStarvation(void);
	virtual void eat(void);
	virtual bool isPrey(void);

};

class ant: public organism {
public:

	virtual int whatAmI(void);
	virtual grid move(grid Board);
	virtual grid breed(grid G);
	virtual bool isPrey(void);



};

class doodlebug: public organism {
public:


	doodlebug();

	virtual int whatAmI(void);
	virtual grid move(grid Board);
	virtual grid breed(grid G);
	virtual int getStarvation(void);
	virtual bool isPrey(void);


};







#endif