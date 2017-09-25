// grid.h -- Alp Piskin

#ifndef GRID_H_
#define GRID_H_

#include <stdio.h>
#include <stdlib.h>

#include "life.h"

// for better data structure, we encapsulate width and height with the data (The Actual Grid)
typedef struct Grid {
	Life** data;
	unsigned width;
	unsigned height;
} Grid;

// Function Prototypes
Grid createGrid(unsigned width, unsigned height);
int loadGridFromFile(const char* filename, Grid* grid);
void printGrid(Grid* grid);
void processGrid(Grid* grid);
void iterateGrid(Grid* grid);
int isGridRepeating(Grid* grid);
int isGridAlternating(Grid* grid);
int isGridDead(Grid* grid);

#endif /* GRID_H_ */
