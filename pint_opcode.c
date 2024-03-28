#include "monty.h"
/**
 * pint_char - prints the character at the top of the stack
 * @stack: pointer to the top of the stack
 * @encounter: line number where the operation is encountered
 */
void pint_char(stack_t **stack, unsigned int encounter)
{
	int ch;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: ERROR,THE STACK IS EMPTY\n", encounter);
		exit(EXIT_FAILURE);
	}

	ch = (*stack)->n;
	if (ch < 0 || ch > 127)
	{
		fprintf(stderr, "L%d: ERROR, OUT OF RANGE\n", encounter);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ch);
}
/**
 * pint_int - prints the integer at the top of the stack
 * @stack: pointer to the top of the stack
 * @encounter: line number where the operation is encountered
 */
void pint_int(stack_t **stack, unsigned int encounter)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", encounter);
		free(header.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pint_string - prints the string stored in the stack
 * @stack: pointer to the top of the stack
 * @encounter: line number where the
 * operation is encountered
 */
void pint_string(stack_t **stack, unsigned int encounter)
{
	stack_t *current = *stack;
	(void) encounter;

	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
