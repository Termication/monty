#include  "monty.h"

/**
 * the_pop_op - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @encounter: line number where the operation is encountered
 */
void the_pop_op(stack_t **stack, unsigned int encounter)
{
	stack_t *temp_node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", encounter);
		free(header.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	temp_node = (*stack)->next;
	free(*stack);

	*stack = temp_node;

	if (*stack != NULL)
		(*stack)->prev = NULL;
}
