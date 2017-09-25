// main.c -- Alp Piskin

#include "grid.h"

unsigned int column, row, gens;
char print = 'n';
char pause = 'n';

int main(int argc, const char* argv[]){

	if (argc < 4) {
		printf("Not enough arguments\n");
		return 0;
	} else if (argc > 7) {
		printf("Too many arguments\n");
		return 0;
	}

	column = atoi(argv[1]);
	row = atoi(argv[2]);
	gens = atoi(argv[3]);

	Grid g = createGrid(column, row);

	if(loadGridFromFile(argv[4], &g)){
		printf(" Error loading grid ...\n");
		return 1;
	}

	if (gens <= 0) {
		printf("Error: Cannot Generate Generations\n");
		return 0;
	}

	char print = 'n', pause = 'n';

	if (argc == 7) {
		print = *argv[5];
		pause = *argv[6];
	} else if (argc == 6) {
		print = *argv[5];
	}

	printf("--LOADED--\n");
	printGrid(&g);
	printf("\n\n--PLAYING--\n\n");

	unsigned i;
	for(i = 0; i < gens; i++){
		processGrid(&g);
		if(isGridRepeating(&g)){
			if (print != 'y') printGrid(&g);
			printf("\nREPEATING! GEN: %d\n", i);
			return 0;
		}
	 	if(isGridAlternating(&g)){
			if (print != 'y') printGrid(&g);
			printf("\nALTERNATING! GEN: %d\n", i);
			return 0;
		}

		iterateGrid(&g);
		if (print == 'y') printGrid(&g);
		if (print == 'y' && pause == 'y') {
			printf("\nPress Enter to continue: \n");
			getchar();
		}

		if(isGridDead(&g)){
			if (print != 'y') printGrid(&g);
			printf("\nDEAD! GEN: %d\n", i);
			return 0;
		}
	}
	printGrid(&g);
	printf("\n GENERATIONS ENDED \nGEN: %d\n", i);
	return 0;
}
