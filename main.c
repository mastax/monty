#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry Point
 * @argc: Args count
 * @argv: list of args
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
 * @n: Nbr to Go Inside The Node.
 * Return: Sucess a Pointer To The Node. Otherwise NULL.
 */
stack_t *creat_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_handling(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
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

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * push_to_queue - Adds Node To The Queue.
 * @new_node: Pointer To The New Node.
 * @ln: Line Number Of The Opcode.
 */
void push_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
