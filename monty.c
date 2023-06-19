#include "monty.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, and 1 on failure
 */
int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	return (0);
}
