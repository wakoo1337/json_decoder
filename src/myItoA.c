#include <stdlib.h>
#include <stdint.h>

#include "myItoA.h"
char *myItoA(const int64_t x, char scratchpad[SCRATCHPAD_SIZE]) {
	unsigned int offset = SCRATCHPAD_SIZE-1;
	scratchpad[offset] = '\0';
	offset--;
	int64_t x_copy = x;
	do {
		scratchpad[offset] = '0' + abs(x_copy % 10);
		x_copy /= 10;
		offset--;
	} while (x_copy != 0);
	if (x < 0) scratchpad[offset] = '-';
	else offset++;
	return &scratchpad[offset];
};
