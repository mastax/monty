#include "monty.h"

/**
 * mul_sec_to_top - Adds the top 2 elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_nbr: Interger representing the line number of of the opcode.
 */
void mul_sec_to_top(stack_t **stck, unsigned int line_nbr)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		more_error_handling(8, line_nbr, "mul");

	(*stck) = (*stck)->next;
	sum = (*stck)->n * (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}


/**
 * mod_sec_to_top - Adds the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod_sec_to_top(stack_t **stck, unsigned int line_nbr)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)

		more_error_handling(8, line_nbr, "mod");


	if ((*stck)->n == 0)
		more_error_handling(9, line_nbr);
	(*stck) = (*stck)->next;
	sum = (*stck)->n % (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
