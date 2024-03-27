#ifndef MONTY_H
#define MONTY_H

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
        int n;
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
int parse_line_to_call_func(char *buffer, int line_number, int format);
void find_and_match(char *opcode, char *value, int ln, int format);
int len_chars(FILE *);

/*Stack operations*/
stack_t *creat_node(int n);
void free_aloc_nodes(void);
void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln);
void push_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);
void print_all_stack(stack_t **stack, unsigned int line_number);
void call_function(op_func func, char *op, char *val, int ln, int format);



void pop_top_stack(stack_t **stack, unsigned int line_number);
void print_top_stack(stack_t **stack, unsigned int line_number);
void nop_do_nothing(stack_t **stack, unsigned int line_number);
void swap_2_at_top(stack_t **stack, unsigned int line_number);

/*Math operations with nodes*/
void add_2_at_top(stack_t **stack, unsigned int line_number);
void sub_2_at_top(stack_t **stack, unsigned int line_number);
void div_sec_to_top(stack_t **stack, unsigned int line_number);
void mul_sec_to_top(stack_t **stack, unsigned int line_number);
void mod_sec_to_top(stack_t **stack, unsigned int line_number);

/*String operations*/
void print_char_top_stack(stack_t **stack, unsigned int line_number);
void print_str_top_stack(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotl_stack(stack_t **stack, __attribute__((unused))unsigned int ln);

/*Error hanlding*/
void error_handling(int error_code, ...);
void more_error_handling(int error_code, ...);
void string_error_handling(int error_code, ...);
void rotr_stack(stack_t **stack, __attribute__((unused))unsigned int ln);

#endif
