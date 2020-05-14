#include "monty.h"

#define DELIMITER " \n\t"
/**
 * split_line - splits line to tokens
 * @data: a pointer to the struct of data
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
int split_line(data_t *data)
{
	char *token;
	size_t size = 4, new_size, i = 0;

	data->args = malloc(size * sizeof(char *));
	if (data->args == NULL)
		push_error(11);
	token = strtok(data->line, DELIMITER);
	while (token)
	{
		data->args[i++] =  token;
		if (i >= size)
		{
			new_size = size * 2;
			data->args = _realloc(data->args, size * sizeof(char *),
					new_size * sizeof(char *));
			if (data->args == NULL)
				push_error(11);
			size = new_size;
		}
		token = strtok(NULL, DELIMITER);
	}
	data->args[i] = NULL;
	return (0);
}
#undef DELIMITER

/**
 * _isdigit - checks for a digit from 0 to 9
 * @str: the integer to be checked
 *
 * Return: 1 if is digit, 0 otherwise
 */
int _isdigit(char *str)
{
	if (str == NULL)
		return (1);
	while (str++)
	{
		if (*str >= 48 && *str <= 57)
			return (1);
	}
	return (0);
}