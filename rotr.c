#include "monty.h"

/**
 * rotate_num2 - Rotates the stack to the bottom
 * @stack: Pointer to the top of the stack
 * @encounter: The line number where the instruction appears
 *
 * Description:
 * This function rotates the stack to the bottom by moving the top element
 * to the bottom. If the stack is empty or
 * contains only one element, the rotation
 * has no effect.
 */
void rotate_num2(stack_t **stack,
		__attribute__((unused)) unsigned int encounter)
{
	stack_t *clone;

	clone = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (clone->next)
	{
		clone = clone->next;
	}
	clone->next = *stack;
	clone->prev->next = NULL;
	clone->prev = NULL;
	(*stack)->prev = clone;
	(*stack) = clone;
}
