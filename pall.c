#include "monty.h"

/**
 * print_stack - Prints all elements in the stack.
 * @stack: Double pointer to the head of the stack.
 * @encounter: Line number in the file (unused in this function)
 */
void print_stack(stack_t **stack, unsigned int encounter)
{
	stack_t *cur = *stack;

	(void)encounter; /* Unused parameter */

	while (cur != NULL)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}
