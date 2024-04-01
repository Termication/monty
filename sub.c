#include "monty.h"
/**
 * substitute - Subtracts the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @encounter: The line number where the instruction appears
 *
 * Description: This function subtracts the value of the second element from
 * the value of the top element of the stack and replaces the top element with
 * the result. It then removes the second element from the stack.
 * If the stack contains fewer than two elements, it prints an error message
 * and exits with failure.
 */
void substitute(stack_t **stack, unsigned int encounter)
{
	int result;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", encounter);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	result = tmp->next->n - tmp->n;
	tmp->next->n = result;
	*stack = tmp->next;
	free(tmp);
}
