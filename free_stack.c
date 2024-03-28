#include "monty.h"
/**
 * free_stack - frees memory allocated for a stack
 * @stack: pointer to the top of the stack
 *
 * Description: This function frees the memory allocated for a stack.
 * It traverses the stack from the top to the bottom, freeing each node
 * as it goes.
 */
void free_stack(stack_t *stack)
{
	stack_t *current_node;

	while (stack != NULL)
	{
		current_node = stack;
		stack = stack->next;
		free(current_node);
	}
}
