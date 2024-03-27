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
 * @fd: pointer to FD
 * Return: void
 */

void ft_read(FILE *fd)
{
	int line_nbr, form = 0;
	char *buff = NULL;
	size_t len = 0;
	ssize_t x = getline(&buff, &len, fd);

	for (line_nbr = 1; x != -1; line_nbr++)
	{
		form = parse_line_to_call_func(buff, line_nbr, form);
	}
	free(buff);
}


/**
 * parse_line_to_call_func - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @line_nbr: line number
 * @form:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line_to_call_func(char *buff, int line_nbr, int form)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buff == NULL)
		error_handling(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (form);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_and_match(opcode, value, line_nbr, form);
	return (form);
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
void find_and_match(char *opcode, char *val, int ln, int form)
{
	int x;
	int flg;

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

	for (flg = 1, x = 0; func_list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, func_list[x].opcode) == 0)
		{
			call_function(func_list[x].f, opcode, val, ln, form);
			flg = 0;
		}
	}
	if (flg == 1)
		error_handling(3, ln, opcode);
}


/**
 * call_function - Calls the required function.
 * @func: Pointer To The Function That Is About To Be Called.
 * @op: string representing the opcode.
 * @value: string representing a numeric value.
 * @line: line numeber for the instruction.
 * @form: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_function(op_func func, char *op, char *value, int line, int form)
{
	stack_t *node;
	int flg;
	int x;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flg = -1;
		}
		if (value == NULL)
			error_handling(5, line);
		for (x = 0; value[x] != '\0'; x++)
		{
			if (isdigit(value[x]) == 0)
				error_handling(5, line);
		}
		node = creat_node(atoi(value) * flg);
		if (form == 0)
			func(&node, line);
		if (form == 1)
			push_to_queue(&node, line);
	}
	else
		func(&head, line);
}
