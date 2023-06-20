#include "monty.h"

/**
 * add_nodeint_end - adds a new node the end of the stack
 * @h: the head of the stack
 * @n: the node data
 * Return: The address of the new node
*/
stack_t *add_nodeint_end(stack_t **h, const int n)
{
	stack_t *new, *current;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;

	if (*h == NULL)
	{
		*h = new;
		new->prev = NULL;
	}
	else
	{
		current = *h;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
	return (new);
}

/**
 * free_stack - frees the stack
 * @head: The head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

/**
 * stack_len - return stack length
 * @head: the giving stack
 * Return: the length of the stack
 */
int stack_len(stack_t *head)
{
	stack_t *tmp = head;
	int len = 0;

	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
