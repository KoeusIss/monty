#include "monty.h"

int process_line(stack_t **stack)
{
	instruction_t inst[] = {
		{"push", add_dnodeint},
		{"pall", print_dlistint}
	};
	char *token;
	int i = 0, new_size, size = 2;

	data.args = malloc(size * sizeof(char **));
	if (data.args == NULL)
		push_error(11);
	token = strtok(data.line, " \n");
	while (token)
	{
		data.args[i++] = token;
		token = strtok(NULL, " \n");
		if (i > size)
		{
			new_size = size * 2;
			data.args = _realloc(data.args, size, new_size);
			if (data.args == NULL)
				push_error(11);
			size = new_size;
		}
	}
	i = 0;
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
