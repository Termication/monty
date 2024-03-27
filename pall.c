#include "monty.h"

/**
 * print_stack - Prints all elements in the stack.
 * @stack: Double pointer to the head of the stack.
 * @encounter: Line number in the file (unused in this function).
 */
void print_stack(stack_t **stack, unsigned int encounter)
{
	(void)encounter; /* Unused parameter */

	stack_t *cur = *stack;

	while (cur != NULL)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}
