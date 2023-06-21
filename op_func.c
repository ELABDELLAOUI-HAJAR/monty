#include "monty.h"

/**
 * _push - pushes an integer to stack
 * @stack: The stack
 * @line_number: The line number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	if (!g_info.arg || is_number(g_info.arg) == 1)
		op_error(2, *stack, g_info.opcode, line_number);

	if (!add_nodeint_end(stack, atoi(g_info.arg)))
		op_error(1, *stack);
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

	while (current->next != NULL)
		current = current->next;

	while (current != NULL)
	{
		printf("%d\n", current->n);
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
		op_error(3, *stack, g_info.opcode, line_number);

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
		op_error(4, *stack, g_info.opcode, line_number);

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
		op_error(5, *stack, g_info.opcode, line_number);

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

