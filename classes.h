#ifndef CLASSES_H 
#define CLASSES_H

#include <cstdio>
#include <cstdlib>

class organism;

class grid {
public:
	int gridSize;
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

	organism();
	virtual ~organism();

	virtual int whatAmI(void);
	virtual void move(grid G);
	virtual void breed(grid G);
	virtual void getStarvation(void);
	virtual void eat(void);
	bool isPrey(void);

};

class ant: public organism {
public:

	virtual int whatAmI(void);
	virtual void move(grid G);
	virtual void breed(grid G);
	



};

class doodlebug: public organism {
public:

	int starvation;

	doodlebug();

	virtual int whatAmI(void);
	virtual void move(grid G);
	virtual void breed(grid G);
	virtual void getStarvation(void);
	


};







#endif