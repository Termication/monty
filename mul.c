#include "monty.h"

/**
 * multiply - Multiplies the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @encounter: The line number where the instruction appears
 *
 * Description:
 * This function multiplies the value of the second element from
 * the value of the top element of the stack
 * and replaces the second element with
 * the result. It then removes the top element from the stack.
 * If the stack contains fewer than two elements, it prints an error message
 * and exits with failure.
 */
void multiply(stack_t **stack, unsigned int encounter)
{
	int multiplication_result;
	stack_t *current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", encounter);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	multiplication_result = current->next->n * current->n;
	current->next->n = multiplication_result;
	*stack = current->next;
	free(current);
}
