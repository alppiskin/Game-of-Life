// grid.c -- Alp Piskin

#include "grid.h"

// returns the Grid struct type
Grid createGrid(unsigned width, unsigned height){
	Grid grid;
	grid.data = createLifes2d(width, height); // generates the 2D array (the board)
	grid.width = width;
	grid.height = height;
	return grid;
}

// determines the grid size and loads it on the given grid
// returns 0 on success
int loadGridFromFile(const char* filename, Grid* grid){

	FILE *to_read = fopen(filename, "r");
	if(!to_read){
		return 3;
	}

	unsigned x = 0; // relative location on the columns
	unsigned y = 0; // relative location on the rows
	unsigned maxx = 0; // max width
	unsigned maxy = 0; // max height

	// determines the grid size
	while (1) {
			if(x > maxx) maxx = x;
			if(y > maxy) maxy = y;
			if(x > grid->width) return 1;
			if(y > grid->height) return 2;
			int ch = fgetc(to_read);
			if(ch == '\n'){
				y++; x = 0;
			} else if (ch == EOF){
				break;
			} else {
				x++;
			}
	}

	fclose(to_read);

	// loads the grid on the given grid
	to_read = fopen(filename, "r");
	if(!to_read){
		return 3;
	}

	// centers the grid on the given board
	x = 0, y = 0;
	unsigned ox = (grid->width - maxx) / 2;
	unsigned oy = (grid->height - maxy) / 2;
	while(1){
			int ch = fgetc(to_read);
			if(ch == '\n'){
				y++; x = 0;
			} else if (ch == EOF){
				break;
			} else {
				if(ch == 'x' || ch == 'X') grid->data[x+ox][y+oy].current = LIVES;
			 	else grid->data[x+ox][y+oy].current = DIES;
				x++;
			}
	}
	fclose(to_read);
	return 0;
}

// prints the grid
void printGrid(Grid* grid){
	printf("----------------------------------\n");
	unsigned i, k;

	for(k = 0; k < grid->height; k++){
		for(i = 0; i < grid->width; i++){
			if(grid->data[i][k].current == LIVES){
				printf("x ");
			} else {
				printf("o ");
			}
		}
		printf("\n");
	}
}

// returns the next state of the Life struct (among previous (last), current and next cell)
enum State generateNextState(Grid* grid, unsigned x, unsigned y) {
	unsigned total = 0;
	int left = x - 1;
	int right = x + 1;
	int up = y - 1;
	int down = y + 1;

	// checks if the left and up positions are in the boundaries
	// and adjusts the total number of neighbors accordingly
	if(left > -1){
		if(up > -1){
			if(grid->data[left][up].current == LIVES) total++;
		}
		if(down < (int)grid->height){
				if(grid->data[left][down].current == LIVES) total++;
				if(grid->data[x][down].current == LIVES) total++;
		}
		if(grid->data[left][y].current == LIVES) total++;
	} else {
		if(down < (int)grid->height){
			if(grid->data[x][down].current == LIVES) total++;
		}
	}
	if(right < (int)grid->width){
		if(up > -1){
			if(grid->data[right][up].current == LIVES) total++;
			if(grid->data[x][up].current == LIVES) total++;
		}
		if(down < (int)grid->height){
				if(grid->data[right][down].current == LIVES) total++;
		}
		if(grid->data[right][y].current == LIVES) total++;
	} else {
		if(up > -1){
			if(grid->data[x][up].current == LIVES) total++;
		}
	}

	// determines if the cell is living or dying in the end ('x' or 'o')
	if(grid->data[x][y].current == LIVES){
		if(total < 2 || total > 3) return DIES;
		else return LIVES;
	} else {
		if(total == 3) return LIVES;
		else return DIES;
	}
}

// finds the Next State defined in the Life struct and sets the next occurring grid on that state
void processGrid(Grid* grid){
	unsigned i, k;
	for(k = 0; k < grid->height; k++){
		for(i = 0; i < grid->width; i++){
			grid->data[i][k].next = generateNextState(grid, i, k);
		}
	}
}

// sets the current state to the previous (last) one
// sets the next state to the current one
// one step forward in the iteration
void iterateGrid(Grid* grid){
	unsigned i, k;
	for(k = 0; k < grid->height; k++){
		for(i = 0; i < grid->width; i++){
			grid->data[i][k].last = grid->data[i][k].current;
			grid->data[i][k].current = grid->data[i][k].next;
		}
	}
}

// checks if the grid is repeating by checking next and current states
int isGridRepeating(Grid* grid){
	unsigned i, k;
	int state = 1;
	for(k = 0; k < grid->height; k++){
		for(i = 0; i < grid->width; i++){
			if(grid->data[i][k].current != grid->data[i][k].next){
				state = 0;
			}
		}
	}
	return state;
}

// checks the next state and the last state
// returns true (1) when the grid is alternating
// returns false (0) when the grid is not alternating
int isGridAlternating(Grid* grid){
	unsigned i, k;
	int state = 1;
	for(k = 0; k < grid->height; k++){
		for(i = 0; i < grid->width; i++){
			if(grid->data[i][k].last != grid->data[i][k].next){
				state = 0;
			}
		}
	}
	return state;
}

// checks if the whole grid is made of 'o's
// returns true (1) when the whole grid is dead
// returns false (0) when at least one cell in the grid is alive
int isGridDead(Grid* grid){
	unsigned i, k;
	int state = 1;
	for(k = 0; k < grid->height; k++){
		for(i = 0; i < grid->width; i++){
			if(grid->data[i][k].current == LIVES){
				state = 0;
			}
		}
	}
	return state;
}
