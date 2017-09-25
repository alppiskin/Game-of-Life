// life.h -- Alp Piskin

#ifndef LIFE_H_
#define LIFE_H_

#include <stdio.h>
#include <stdlib.h>

// defines a state for the current cell's condition (Lives or Dies)
enum State {
	LIVES,
	DIES,
};

//
typedef struct Life {
	enum State last;
	enum State current;
	enum State next;
} Life;

Life** createLifes2d(unsigned width, unsigned height);

#endif /* LIFE_H_ */
