#include "monty.h"

/**
 * ft_open - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void ft_open(char *file_nam)
{
	FILE *fd = fopen(file_nam, "r");

	if (file_nam == NULL || fd == NULL)
		error_handling(2, file_nam);

	ft_read(fd);
	fclose(fd);
}


/**
 * ft_read - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void ft_read(FILE *fd)
{
	int line_nbr, form = 0;
	char *buff = NULL;
	size_t len = 0;

	for (line_nbr = 1; getline(&buff, &len, fd) != -1; line_nbr++)
	{
		form = parse_line_to_call_func(buff, line_nbr, form);
	}
	free(buff);
}


/**
 * parse_line_to_call_func - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line_to_call_func(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		error_handling(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_and_match(opcode, value, line_number, format);
	return (format);
}

/**
 * find_and_match - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_and_match(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_to_stack},
		{"pall", print_all_stack},
		{"pint", print_top_stack},
		{"pop", pop_top_stack},
		{"nop", nop_do_nothing},
		{"swap", swap_2_at_top},
		{"add", add_2_at_top},
		{"sub", sub_2_at_top},
		{"div", div_sec_to_top},
		{"mul", mul_sec_to_top},
		{"mod", mod_sec_to_top},
		{"pchar", print_char_top_stack},
		{"pstr", print_str_top_stack},
		{"rotl", rotl_stack},
		{"rotr", rotr_stack},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_function(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error_handling(3, ln, opcode);
}


/**
 * call_function - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_function(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error_handling(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error_handling(5, ln);
		}
		node = creat_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			push_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
