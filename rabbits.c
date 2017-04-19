/**
 * Rabbit population growth simulation
 *
 * Copyright 2017 Harvey Manfrenjensenden
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int gen, births, i;
	long long pop;

	if (argc != 4) {
		fprintf(stderr, "usage: rabbits population avg_births "
			"num_generations\n");
		exit(1);
	}

	pop = strtol(argv[1], NULL, 10);
	births = strtol(argv[2], NULL, 10);
	gen = strtol(argv[3], NULL, 10);

	for (i = 0; i < gen; i++) {
		printf("Population after %2d generations: %lld\n", i, pop);

		pop += pop / 2 * births;
	}

	return 0;
}
