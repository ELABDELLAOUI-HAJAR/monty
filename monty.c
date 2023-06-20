#include "monty.h"

global_info g_info;

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, and 1 on failure
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}

	g_info.file = fopen(av[1], "r");
	if (!g_info.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	monty_interpreter(&stack);

	return (0);
}
