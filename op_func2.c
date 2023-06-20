#include "monty.h"

/**
 * _mod - computes the rest of the division of the two top
 * elements of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *prev = NULL;


	if (stack_len(*stack) < 2)
		op_error(5, *stack, g_info.opcode, line_number);

	current = *stack;

	while (current != NULL)
	{
		if (current->next == NULL)
		{
			if (current->n == 0)
				op_error_bis(7, *stack, g_info.opcode, line_number);
			prev->n = prev->n % current->n;
			prev->next = NULL;
			free(current);
			break;
		}
		prev = current;
		current = current->next;
	}
}

/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!stack || !(*stack))
		op_error(3, *stack, g_info.opcode, line_number);

	current = *stack;

	while (current)
	{
		if (current->next == NULL)
		{
			if (current->n >= 0  && current->n <= 127)
				printf("%c\n", current->n);
			else
				op_error_bis(8, *stack, g_info.opcode, line_number);
		}
		current = current->next;
	}
}
