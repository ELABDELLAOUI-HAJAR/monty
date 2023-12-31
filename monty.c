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
		global_error(1);

	g_info.file = fopen(av[1], "r");
	if (!g_info.file)
		global_error(2, av[1]);

	monty_interpreter(&stack);

	fclose(g_info.file);
	return (0);
}
