#include "monty.h"


/**
 * push_to_stack - Adds a node to the stack.
 * @nw_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void push_to_stack(stack_t **nw_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (nw_node == NULL || *nw_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nw_node;
		return;
	}
	tmp = head;
	head = *nw_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_all_stack - Adds a node to the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_nbr: line number of  the opcode.
 */
void print_all_stack(stack_t **stck, unsigned int line_nbr)
{
	stack_t *tmp;

	(void) line_nbr;
	if (stck == NULL)
		exit(EXIT_FAILURE);
	tmp = *stck;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top_stack - Adds a node to the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_nbr: Interger representing the line number of of the opcode.
 */
void pop_top_stack(stack_t **stck, unsigned int line_nbr)
{
	stack_t *tmp;

	if (stck == NULL || *stck == NULL)
		more_error_handling(7, line_nbr);

	tmp = *stck;
	*stck = tmp->next;
	if (*stck != NULL)
		(*stck)->prev = NULL;
	free(tmp);
}

/**
 * print_top_stack- Prints the top node of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @line_nbr: Interger representing the line number of of the opcode.
 */
void print_top_stack(stack_t **stck, unsigned int line_nbr)
{
	if (stck == NULL || *stck == NULL)
		more_error_handling(6, line_nbr);
	printf("%d\n", (*stck)->n);
}
