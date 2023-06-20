#include "monty.h"

/**
 * _push - pushes an integer to stack
 * @stack: The stack
 * @line_number: The line number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	if (!g_info.arg || is_number(g_info.arg) == 1)
	{
		free_all(*stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!add_nodeint_end(stack, atoi(g_info.arg)))
	{
		free_all(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * _pall - prints all the values on the stack, starting from
 * the top of the stack.
 * @stack: The stack
 * @line_number: The line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		if (current->next == NULL)
			break;
		current = current->next;
	}

	while (current != NULL)
	{
		printf("%d\n", current->n);
		if (current->prev == NULL)
			break;
		current = current->prev;
	}
}

/**
 * _pint - prints the value of the top elmt of the stack
 * @stack: the giving stack
 * @line_number: the line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	while (current != NULL)
	{
		if (current->next == NULL)
		{
			printf("%d\n", current->n);
			break;
		}
		current = current->next;
	}
}

/**
 * _pop - removes the top element of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *prev = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	while (current != NULL)
	{
		if (current->next == NULL)
		{
			if (current->prev != NULL)
				prev->next = NULL;
			else
				*stack = NULL;
			free(current);
			break;
		}
		prev = current;
		current = current->next;
	}
}


/**
 * _swap - swaps the top two elements of the stack
 * @stack: a pointer the the first element of the stack
 * @line_number: the line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *prev = NULL;
	int tmp = 0;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	while (current != NULL)
	{
		if (current->next == NULL)
		{
			tmp = prev->n;
			prev->n = current->n;
			current->n = tmp;
			break;
		}
		prev = current;
		current = current->next;
	}
}

