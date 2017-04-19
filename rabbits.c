/**
 * Rabbit population growth simulation
 *
 * Copyright 2017 Harvey Manfrenjensenden
 */

#include <stdio.h>
#include <stdlib.h>

void errorExit(char *msg);

int main(int argc, char **argv)
{
	int gen, births, i;
	long long pop;
	char *badchar;

	if (argc != 4) {
		fprintf(stderr, "usage: rabbits population avg_births "
			"num_generations\n");
		exit(1);
	}

	pop = strtol(argv[1], &badchar, 10);
	if (*badchar != '\0') {
		errorExit("population must be a positive integer");
	}

	births = strtol(argv[2], &badchar, 10);
	if (*badchar != '\0') {
		errorExit("avg_births must be a positive integer");
	}

	gen = strtol(argv[3], &badchar, 10);
	if (*badchar != '\0') {
		errorExit("num_generations must be a positive integer");
	}

	for (i = 0; i < gen; i++) {
		printf("Population after %2d generations: %lld\n", i, pop);

		pop += pop / 2 * births;
	}

	return 0;
}

void errorExit(char *msg)
{
	fprintf(stderr, "rabbits: %s\n", msg);
	exit(2);
}
