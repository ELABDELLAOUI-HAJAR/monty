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

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	if (!stack || !(*stack))
	{
		printf("\n");
		return;
	}

	current = *stack;

	while (current->next != NULL)
		current = current->next;

	while (current != NULL)
	{
		if (current->n > 0  && current->n <= 127)
			printf("%c", current->n);
		else
			break;
		current = current->prev;
	}
	printf("\n");
}


/**
 * _rotl - rotates the stack to the top
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *tmp;

	(void)line_number;
	if (!stack || !(*stack) || stack_len(*stack) == 1)
		return;

	current = *stack;

	while (current->next != NULL)
		current = current->next;
	tmp = current;
	if (tmp->prev != NULL)
		(tmp->prev)->next = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * _rotr - rotates the stack to the bottom.
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *prev = NULL, *curr, *next, *tmp;

	(void) line_number;

	if (!stack || !(*stack))
		return;

	curr = *stack;

	while (curr)
	{
		tmp = curr;
		next = curr->next;

		curr->next = prev;
		curr->prev = next;

		curr = next;
		prev = tmp;
	}
	*stack = prev;
}
