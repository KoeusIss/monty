#include "monty.h"

/**
 * main - main function
 *
 * Return: (Success) EXIT_SUCCESS
 * ------- (Fail) EXIT_FAILURE
 */
int main(int ac, char **av)
{
	FILE *fp;
	data_t data;
	ssize_t n_read;
	size_t length = 0;

	memset((void *) &data, 0, sizeof(data));
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((n_read = getline(&data.line, &length, fp)) > 0)
	{
		process_line(&data);
	}
	free(data.line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
