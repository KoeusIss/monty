#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of a linked list
 * @stack: a pointer to the linked list
 * @line_number: the line number
 *
 * Return: void
 */
void
add_dnodeint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		push_error(11);
	if (isdigit(*(data.args)[1]) == 0)
		push_error(16);
	new_node->n = atoi(data.args[1]);
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->prev = NULL;
	}
	*stack = new_node;
}
/**
 * print_dlistint - prints all elements of a doubly list
 * @stack: the pointer to the head
 * @line_number: the line number
 *
 * Return: void
 */
void
print_dlistint(stack_t **stack,
	unsigned int line_number __attribute__((unused)))
{
	stack_t *cursor;

	cursor = *stack;
	while (cursor)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}
/**
 * print_reverse - prints from bottom to top
 * @stack: the pointer to the head
 * @line_number: the line number
 *
 * Return: void
 */
void print_reverse(stack_t **stack,
	unsigned int line_number __attribute__((unused)))
{
	stack_t *cursor;

	if (*stack == NULL)
		push_error(17);
	cursor = *stack;
	while (cursor->next)
		cursor = cursor->next;
	while (cursor)
	{
		fprintf(stdout, "%d\n", cursor->n);
		cursor = cursor->prev;
	}
}
