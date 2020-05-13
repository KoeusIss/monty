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
	fclose(fp);
	return (EXIT_SUCCESS);
}
