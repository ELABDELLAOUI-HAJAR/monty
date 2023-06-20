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
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	while (current != NULL)
	{
		if (current->next == NULL)
		{
			if (current->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_number);
				free_all(*stack);
				exit(EXIT_FAILURE);
			}
			prev->n = prev->n % current->n;
			prev->next = NULL;
			free(current);
			break;
		}
		prev = current;
		current = current->next;
	}
}
