#include "monty.h"


/**
 * main - Entry Point
 * @ac: Ac count
 * @av: list of args vector
 * Return: Always 0
 */

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ft_open(av[1]);
	free_aloc_nodes();
	return (0);
}

/**
 * creat_node - Creates a node.
 * @nbr: Nbr to Go Inside The Node.
 * Return: Sucess a Pointer To The Node. Otherwise NULL.
 */
stack_t *creat_node(int nbr)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_handling(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = nbr;
	return (node);
}

/**
 * free_aloc_nodes - Free Nodes In The Stack.
 */
void free_aloc_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * push_to_queue - Adds Node To The Queue.
 * @nw_node: Pointer To The New Node.
 * @line: Line Number Of The Opcode.
 */
void push_to_queue(stack_t **nw_node, __attribute__((unused))unsigned int line)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *nw_node;
	(*nw_node)->prev = tmp;

}
