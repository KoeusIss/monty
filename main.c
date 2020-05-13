#include "monty.h"
data_t data;
/**
 * main - main function
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: (Success) EXIT_SUCCESS
 * ------- (Fail) EXIT_FAILURE
 */
int main(int ac, char **av)
{
	ssize_t n_read;
	size_t length = 0;
	stack_t *stack = NULL;

	memset((void *) &data, 0, sizeof(data));
	if (ac != 2)
		push_error(12);
	data.filename = av[1];
	data.fp = fopen(data.filename, "r");
	if (data.fp == NULL)
		push_error(14);
	while ((n_read = getline(&data.line, &length, data.fp)) > 0)
	{
		process_line(&stack);
		data.line_number++;
	}
	free_data();
	return (EXIT_SUCCESS);
}
