// life.c -- Alp Piskin

#include "life.h"

Life** createLifes2d(unsigned width, unsigned height)
{
	Life** grid = (Life**)malloc(sizeof(Life*)*width); // allocates space for a 2d array

	unsigned i;
	unsigned k;

	// allocates each individual array inside the 2D array and sets all elements to 'o' (DIES State)
	for(i = 0; i < width; i++){
		grid[i] = (Life*)malloc(sizeof(Life)*height);
		for(k = 0; k < height; k++){
			grid[i][k].current = DIES;
		}
	}
	return grid;
}

