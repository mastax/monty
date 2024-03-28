#include "monty.h"

/**
 * error_handling - Prints  error messages determined by their error code.
 * @err_code: The error codes are the following:
 * 1 => The User Does.nt Give ANY File or MORE Than One File To The Program.
 * 2 => The File can be opned .
 * 3 => The file contains an invalid instruct.
 * 4 => When Program is unable to memo alloc more memory.
 * 5 => When the Param passed to the instruct "push" isn't an int.
 * 6 => When stack it empty for pint.
 * 7 => When  stack it empty for pop.
 * 8 => When stack is too shoort for op.
 */
void error_handling(int err_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_aloc_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error_handling - handles the errors.
 * @err_code: The error codes are the following:
 * 6 => When stack it empty for p_int.
 * 7 => When stack it empty for pop.
 * 8 => When stack is too short for op.
 * 9 => Division by 0.
 */
void more_error_handling(int err_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_aloc_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - Handles errors.
 * @err_code: The error codes are the following:
 * 10 ~> The number inside a node is outside ASCII range.
 * 11 ~> The stack is empty.
 */
void string_error_handling(int err_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, err_code);
	l_num = va_arg(ag, int);
	switch (err_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_aloc_nodes();
	exit(EXIT_FAILURE);
}
