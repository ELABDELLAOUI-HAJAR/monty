#include "monty.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, and 1 on failure
 */
int main(int ac, char **av)
{
	(void) av;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}
