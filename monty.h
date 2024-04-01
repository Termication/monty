#ifndef _MONTY_H_
#define _MONTY_H_

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ctype.h>


/**
 * struct the_head - houses ptr variables
 * @arg: char ptr
 * @file: file ptr
 * @line: char ptr 2
 * @help: int var:wq
 *
 */
typedef struct the_head
{
	char *arg;
	FILE *file;
	char *line;
	int help;
} head;

extern head header;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void add_opcode(stack_t **stack, unsigned int encounter);
void swap_opcode(stack_t **stack, unsigned int encounter);
void nop_opcode(stack_t **stack, unsigned int encounter);
void free_stack(stack_t *stack);
void the_pop_op(stack_t **stack, unsigned int encounter);
void pint_char(stack_t **stack, unsigned int encounter);
void pint_string(stack_t **stack, unsigned int encounter);
void pint_int(stack_t **stack, unsigned int encounter);
void handle_error(stack_t **stack, int exit_code);
int validate_integer(char *str_val);
void opcode_push(stack_t **stack, unsigned int line_num);
void print_stack(stack_t **stack, unsigned int encounter);
int executable(char *content,
		stack_t **stack, unsigned int counter, FILE *file);
void line_reader(stack_t **stack);
stack_t *new_int_node(stack_t **stack, const int value);
void _stack(stack_t **stack, unsigned int encounter);
void multiply(stack_t **stack, unsigned int encounter);
void modulus(stack_t **stack, unsigned int encounter);
void divide(stack_t **stack, unsigned int encounter);
void substitute(stack_t **stack, unsigned int encounter);
void rotate(stack_t **stack, __attribute__((unused)) unsigned int encounter);
void rotate_num2(stack_t **stack,
		__attribute__((unused)) unsigned int encounter);
void _queue(stack_t **stack, unsigned int encounter);

#endif /* monty.h */
