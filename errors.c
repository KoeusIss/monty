#include "monty.h"
/**
 * push_error - pushs errors
 * @err_code: error code
 *
 * Return: void
 */
void push_error(short int err_code)
{
	switch (err_code)
	{
	case 11:
		fprintf(stderr, "Error: malloc failed\n");
		free_data();
		break;
	case 12:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 14:
		fprintf(stderr, "Error: Can't open file %s\n", data.filename);
		break;
	case 15:
		fprintf(stderr, "L%d: unknown instruction %s\n",
			data.line_number, data.args[0]);
		free_data();
		break;
	case 16:
		fprintf(stderr, "L%d: usage: push integer\n", data.line_number);
		free_data();
		break;
	case 17:
		fprintf(stderr, "L%d: can't pint, stack empty\n", data.line_number);
		free_data();
		break;
	case 18:
		fprintf(stderr, "L%d: can't pop an empty stack\n", data.line_number);
		free_data();
		break;
	default:
		break;
	}
	exit(EXIT_FAILURE);
}
