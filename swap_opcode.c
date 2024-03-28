#include "monty.h"
/**
 * swap_opcode - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @encounter: line number where the operation is encountered
 */
void swap_opcode(stack_t **stack, unsigned int encounter)
{
	stack_t *temp_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", encounter);
		free(header.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp_node = (*stack)->next;
	(*stack)->next = temp_node->next;

	if (temp_node->next != NULL)
		temp_node->next->prev = *stack;

	temp_node->prev = NULL;
	temp_node->next = *stack;
	(*stack)->prev = temp_node;
	*stack = temp_node;
}
