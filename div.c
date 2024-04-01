#include "monty.h"
/**
 * divide - Divides the second element of
 * the stack by the top element
 * @stack: Pointer to the top of the stack
 * @encounter: The line number where the instruction appears
 *
 * Description:
 * This function divides the value of the second element from the value of
 * the top element of the stack and replaces the second element with
 * the result. It then removes the top element from the stack.
 * If the stack contains fewer than two elements, it prints an error message
 * and exits with failure.
 * If the top element is 0, it prints an error message for division by zero
 * and exits with failure.
 */
void divide(stack_t **stack, unsigned int encounter)
{
	stack_t *current;
	int size = 0, result;

	current = *stack;
	while (current)
	{
		current = current->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", encounter);
		fclose(header.file);
		free(header.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", encounter);
		fclose(header.file);
		free(header.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = current->next->n / current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}
