all: compile

compile: generate
	gcc life.o grid.c main.o -o life

generate:
	gcc -c life.c grid.c main.c

clean:
	rm *.o
	rm life