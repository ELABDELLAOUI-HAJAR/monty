#include "monty.h"

/**
 * monty_interpreter - read monty instructions line by line
 * @stack: the stack
 */
void monty_interpreter(stack_t **stack)
{
	size_t n = 0;
	ssize_t nmbr_char;
	void (*p_func)(stack_t **stack, unsigned int line_number);
	unsigned int line_count = 0;
	(void)stack;

	g_info.lifo = 1;
	while (1)
	{
		nmbr_char = getline(&g_info.line, &n, g_info.file);
		if (nmbr_char <= 0)
		{
			free_all(*stack);
			exit(EXIT_SUCCESS);
		}

		line_count++;
		line_parser();

		if (!g_info.opcode || g_info.opcode[0] == '#')
			continue;

		p_func = get_op_func(g_info.opcode);
		if (!p_func)
			op_error_bis(6, *stack, g_info.opcode, line_count);

		p_func(stack, line_count);
	}
}

/**
 * free_all - free alocated memory & stack
 * @stack: the stack
 */
void free_all(stack_t *stack)
{
	free_stack(stack);
	free(g_info.line);
	fclose(g_info.file);
}

/**
 * line_parser - parser a line
 */
void line_parser(void)
{
	const char *delim = " \n\t";

	g_info.opcode = strtok(g_info.line, delim);
	g_info.arg = strtok(NULL, delim);
}

/**
 * is_number - checks if a string is a number
 * @str: the string
 * Return: 0 on success, and 1 otherwise
 */
int is_number(char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (1);

	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;

		if (str[i] < 48 || str[i] > 57)
			return (1);

		i++;
	}

	return (0);
}
