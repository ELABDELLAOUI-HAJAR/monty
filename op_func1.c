#include "monty.h"

/**
 * _add - adds the two top elements of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *prev = NULL;


	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	while (current != NULL)
	{
		if (current->next == NULL)
		{
			prev->n = prev->n + current->n;
			prev->next = NULL;
			free(current);
			break;
		}
		prev = current;
		current = current->next;
	}
}

/**
 * _nop - doesn't do anything
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
