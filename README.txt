ALP PISKIN -- README.txt

----------------------------------------------------------------------------------------------------------------------------------------------------------

SUMMARY:

- life.h creates the enumeration (see: CITATIONS) of state (LIVES 'x' or DIES 'o') and the struct (see: CITATIONS) definition of life which has three enumeration states:
These states include the previous (State: last), current (State: current), and the next (State: next)
 
- life.c creates the 2D array to create the grid, which is the board. In here, the grid has all 'o's because it assumes that the starting grid can be all dead cells
since the grid.c puts all the initial living cells on their respective places on the board.

- grid.h creates another struct (see: CITATIONS) that has the data, the width and the height of the grid.

- grid.c uses the struct GRID and defines the following functions:
	- createGrid: calls the 2D array formation from life.c to create the grid with the input height and weight
	- loadGridFromFile:opens the input file, loads the file on the desired grid and centers it on the grid.
	- printGrid: prints the grid with the chars 'x' and 'o' in the respective places by looping around the whole grid 
	- generateNextState: returns the next state of the Life struct (among previous (last), current and next cell) loops through all the possibilities of the eight neighbors around the cell
	- processGrid: sets the outcome of the generateNextState() onto the Next State of the Life struct in life.h
	- isGridRepeating: checks if the grid is repeating by checking next and current states
	- isGridAlternating: checks the next state and the last state, returns true (1) when the grid is alternating, returns false (0) when the grid is not alternating
	- isGridDead: checks if the whole grid is made of 'o's, returns true (1) when the whole grid is dead, returns false (0) when at least one cell in the grid is alive

----------------------------------------------------------------------------------------------------------------------------------------------------------

CITATIONS:

- For this assignment, I used the concepts enumeration and structs, which we have not covered in the class.
- The websites of reference are:

- http://en.cppreference.com/w/c/language/enum
- http://en.cppreference.com/w/c/language/struct

- I used the enumeration to use a more compact version of switch statements that I would have used if did not
use enumeration
- I used the structs to define the cell ( as LIFE) and the grid (as GRID) and stored data inside. I also used pointers
to access the data inside the memory. (->)
----------------------------------------------------------------------------------------------------------------------------------------------------------

PROBLEM:

- The problem that I ran into was that when I was trying to fill the board with the initial positions of 'x's and 'o's loaded on the grid.
- I solved the problem by debugging and combining two of my previous functions into the loadGridFromFile() function

----------------------------------------------------------------------------------------------------------------------------------------------------------

HOW TO RUN THE PROGRAM:

- Locate the file in the terminal and then the comman should go: ./life [rows] [columns] [gens] input.txt ['y' or 'n' for print] ['y' or 'n' for pause]
- If you input 'y' for the pause: each generation requires to press Enter to proceed.
