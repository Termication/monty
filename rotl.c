#include "monty.h"

/**
 * rotate - Rotates the stack to the top
 * @stack: Pointer to the top of the stack
 * @encounter: The line number where the instruction appears
 *
 * Description:
 * This function rotates the stack to the top by moving the second element
 * to the top. If the stack is empty or contains only one element, the rotation
 * has no effect.
 */
void rotate(stack_t **stack, __attribute__((unused)) unsigned int encounter)
{
	stack_t *current = *stack, *auxiliary;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	auxiliary = (*stack)->next;
	auxiliary->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = current;
	(*stack) = auxiliary;
}
