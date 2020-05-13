#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of a linked list
 * @head: a pointer to the linked list
 * @n: a given integer of the new node
 *
 * Return: (Success) a pointer to the newly add node
 * ------- (Fail) return a NULL
 */
void add_dnodeint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		push_error(11);
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
 * @head: the pointer to the head
 *
 * Return: (Success) a number of the nodes
 * ------- (Fail) return negative number
 */
void print_dlistint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *cursor;

	cursor = *stack;
	while (cursor)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}