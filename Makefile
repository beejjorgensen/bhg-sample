all: rabbits

rabbits: rabbits.c
	cc -Wall -Wextra -g -o $@ $^

.PHONY: all
