#include "monty.h"
/**
 * process_line - process and parse line
 * @stack: the stack
 *
 * Return: integer
 */
int process_line(stack_t **stack)
{
	instruction_t inst[] = {
		{"push", add_dnodeint},
		{"pall", print_dlistint},
		{NULL, NULL}
	};
	int i = 0;

	while ((inst + i)->opcode)
	{
		if (strcmp((inst + i)->opcode, data.args[0]) == 0)
		{
			(inst + i)->f(stack, data.line_number);
			return (0);
		}
		i++;
	}
	if ((inst + i)->opcode == NULL)
		push_error(15);
	return (0);
}