#include "monty.h"

/**
 * nop_do_nothing - Does nothing.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_nbr: Interger representing the line number of of the opcode.
 */
void nop_do_nothing(stack_t **stck, unsigned int line_nbr)
{
	(void)stck;
	(void)line_nbr;
}


/**
 * swap_2_at_top - Swaps the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_nbr: Interger representing the line number of of the opcode.
 */
void swap_2_at_top(stack_t **stck, unsigned int line_nbr)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		more_error_handling(8, line_nbr, "swap");
	tmp = (*stck)->next;
	(*stck)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stck;
	tmp->next = *stck;
	(*stck)->prev = tmp;
	tmp->prev = NULL;
	*stck = tmp;
}

/**
 * add_2_at_top - Adds the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_nbr: Interger representing the line number of of the opcode.
 */
void add_2_at_top(stack_t **stck, unsigned int line_nbr)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		more_error_handling(8, line_nbr, "add");

	(*stck) = (*stck)->next;
	sum = (*stck)->n + (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}


/**
 * sub_2_at_top - Adds the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_nbr: Interger representing the line number of of the opcode.
 */
void sub_2_at_top(stack_t **stck, unsigned int line_nbr)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)

		more_error_handling(8, line_nbr, "sub");


	(*stck) = (*stck)->next;
	sum = (*stck)->n - (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}


/**
 * div_sec_to_top - Adds the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_nbr: Interger representing the line number of of the opcode.
 */
void div_sec_to_top(stack_t **stck, unsigned int line_nbr)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		more_error_handling(8, line_nbr, "div");

	if ((*stck)->n == 0)
		more_error_handling(9, line_nbr);
	(*stck) = (*stck)->next;
	sum = (*stck)->n / (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
