#include "monty.h"
/**
 * new_int_node - Creates a new node with an integer
 * value and adds it to the stack
 * @stack: A pointer to the top of the stack
 * @value: The integer value to be added to the stack
 *
 * Return: A pointer to the newly created node
 *
 * Description: This function allocates memory for a new node, assigns the
 * given integer value to it, and adds it to the top of the stack. If memory
 * allocation fails, it prints an error message to stderr, frees the entire
 * stack, and exits the program with failure status.
 */
stack_t *new_int_node(stack_t **stack, const int value)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	node->n = value;
	node->prev = NULL;

	if (*stack == NULL)
		node->next = NULL;
	else
	{
		node->next = *stack;
		(*stack)->prev = node;
	}
	*stack = node;

	return (node);
}
