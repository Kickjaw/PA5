Program: PA5

Purpose: to simulate the lives of ants and doodlebugs

How to use: in terminal enter ./PA5 gridsize #doodlebugs #ants #time_steps seed pause
		gridsize = is the size of the square grid that is the board
		#doodlebugs = is the number of doodlebugs to start the sim with
		#ants = the number of the ants to start the sim with
		#time_steps = number of steps to run the sim for
		seed = the seed to start the random number generator
		pause = positive int will enable pausing between steps

Problems:

grid class:
creating the 2d array within the grid class was fairly hard for me to create.  It took a little while to understand what i need to acomplish with it.  Once i understood it though it made a lot of sense as to why to have it in a class.  Within the constructor for the class I create the 2d array and initilize it.  What tripped me up was that it is a 2d array of pointers so the array itself is a triple pointer.

Breed:

breed took a while to get working because im an idiot. the first problem is that i had some problems with the program trying to add a bug outside the grid.  this was cuased by not having a default class in switch case.  I solved this by not lettting it get to the switch if it didnt exist in the switch case.  additionally within the breed i tried to create new bugs and insert them into the board and was getting wierd inconsisitnates with the data.  I end up trying my insert bug function which i use to generate the board and it worked perfectly.

Beyond that this prgram was not that difficult for me and I had no other major sticking points.
