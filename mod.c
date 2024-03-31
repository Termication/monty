#include "monty.h"
/**
 * modulus - Computes the modulus of the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @encounter: The line number where the instruction appears
 *
 * Description:
 * This function computes the modulus of the second element from
 * the first element of the stack and replaces the second element with
 * the result. It then removes the top element from the stack.
 * If the stack contains fewer than two elements, it prints an error message
 * and exits with failure.
 * If the first operand (top element) is 0, it prints an error message
 * for division by zero and exits with failure.
 */
void modulus(stack_t **stack, unsigned int encounter)
{
	int first_operand, second_operand;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: Unable to open, stack too short\n", encounter);
		exit(EXIT_FAILURE);
	}

	first_operand = (*stack)->n;
	second_operand = (*stack)->next->n;

	if (first_operand == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", encounter);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = second_operand % first_operand;
	opcode_push(stack, encounter);
}
