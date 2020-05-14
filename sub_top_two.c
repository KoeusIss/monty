#include "monty.h"
/**
 * sub_top_two - adds the top two elements
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void sub_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		push_error(21);
		return;
	}
	tmp->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free(tmp);
	(*stack)->prev = NULL;
}
