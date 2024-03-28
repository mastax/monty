#include "monty.h"

/**
 * print_char_top_stack - Prints the Ascii value.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_nbr: Interger representing the line number of of the opcode.
 */
void print_char_top_stack(stack_t **stck, unsigned int line_nbr)
{
	int ascii;

	if (stck == NULL || *stck == NULL)
		string_error_handling(11, line_nbr);

	ascii = (*stck)->n;
	if (ascii < 0 || ascii > 127)
		string_error_handling(10, line_nbr);
	printf("%c\n", ascii);
}

/**
 * print_str_top_stack - Prints a string.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str_top_stack(stack_t **stck, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stck == NULL || *stck == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stck;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl_stack(stack_t **stck, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		return;

	tmp = *stck;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stck;
	(*stck)->prev = tmp;
	*stck = (*stck)->next;
	(*stck)->prev->next = NULL;
	(*stck)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr_stack(stack_t **stck, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		return;
	tmp = *stck;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stck;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stck)->prev = tmp;
	(*stck) = tmp;
}
