#include "monty.h"

/**
 * get_op_func - get operation function
 * @opcode: the operation code
 * Return: Return the associate function, or NULL if not found
 */
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop}
	};
	int i = 0;

	while (i < 4)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
