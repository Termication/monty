#include "monty.h"
/**
 * add_opcode - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @encounter: line number where the operation is encountered
 *
 * Description: This function adds the top two elements of the stack.
 * If the stack is empty or contains only one element, it prints an error
 * message, frees allocated memory, and exits with EXIT_FAILURE.
 */
void add_opcode(stack_t **stack, unsigned int encounter)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", encounter);
		free(header.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	the_pop_op(stack, encounter);
}
