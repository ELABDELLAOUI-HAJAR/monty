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
	int line_count = 0;
	(void)stack;

	while (1)
	{
		nmbr_char = getline(&g_info.line, &n, g_info.file);
		if (nmbr_char == -1)
		{
			if (feof(g_info.file))
			{
				free_all(*stack);
				exit(EXIT_SUCCESS);
			}
			free_all(*stack);
			exit(EXIT_FAILURE);
		}

		line_count++;
		line_parser();
		p_func = get_op_func(g_info.opcode);
		if (!p_func)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
				line_count, g_info.opcode);
			free_all(*stack);
			exit(EXIT_FAILURE);
		}

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
	const char *delim = " \t\n";

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

	while (str[i])
	{
		if (str[0] == '-')
			i++;

		if (str[i] < 48 || str[i] > 57)
			return (1);

		i++;
	}

	return (0);
}
