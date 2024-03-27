#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - Doubly Linked List Representation Of a Stack (Or Queue)
 * @n: integer
 * @prev: Points To The Previous Element Of The Stack (Or Queue)
 * @next: Points To The Next Element Of The Stack (Or Queue)
 *
 * Description: Doubly Linked List Node Structure
 * for stack, Aueues, LIFO, FIFO
 */
typedef struct stack_s
{
	int		n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - 0pcode and 1ts funct1on
 * @opcode: the 0pcode
 * @f: funct1on to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
/*file operations*/
void ft_open(char *file_nam);
void ft_read(FILE *fd);
int parse_line_to_call_func(char *buff, int line_nbr, int form);
void find_and_match(char *opcode, char *val, int ln, int form);
int len_chars(FILE *);
/*Stack operations*/
stack_t *creat_node(int n);
void free_aloc_nodes(void);
void push_to_stack(stack_t **nw_node, __attribute__((unused))unsigned int ln);
void push_to_queue(stack_t **nw_node, __attribute__((unused))unsigned int ln);
void print_all_stack(stack_t **stck, unsigned int line_nbr);
void call_function(op_func func, char *op, char *value, int line, int form);

void pop_top_stack(stack_t **stck, unsigned int line_nbr);
void print_top_stack(stack_t **stck, unsigned int line_nbr);
void nop_do_nothing(stack_t **stck, unsigned int line_nbr);
void swap_2_at_top(stack_t **stck, unsigned int line_nbr);
/*Math operations with nodes*/
void add_2_at_top(stack_t **stck, unsigned int line_nbr);
void sub_2_at_top(stack_t **stck, unsigned int line_nbr);
void div_sec_to_top(stack_t **stck, unsigned int line_nbr);
void mul_sec_to_top(stack_t **stck, unsigned int line_nbr);
void mod_sec_to_top(stack_t **stck, unsigned int line_nbr);
/*String operations*/
void print_char_top_stack(stack_t **stck, unsigned int line_nbr);
void print_str_top_stack(stack_t **stck, __attribute__((unused))int ln);
void rotl_stack(stack_t **stck, __attribute__((unused))unsigned int ln);
void rotr_stack(stack_t **stck, __attribute__((unused))unsigned int ln);
/*Error hanlding*/
void error_handling(int err_code, ...);
void more_error_handling(int err_code, ...);
void string_error_handling(int err_code, ...);

#endif
