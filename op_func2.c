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

/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	while (current)
	{
		if (current->next == NULL)
		{
			if (current->n >= 0  || current->n <= 127)
			{
				printf("%c\n", current->n);
			}
			else
			{
				fprintf(stderr, "L%d: can't pchar, value out of range\n",
					line_number);
				free_all(*stack);
				exit(EXIT_FAILURE);
			}
		}
		current = current->next;
	}
}
