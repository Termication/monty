#include "monty.h"

/**
 * opcode_push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_num: Line number in the file.
 */
void opcode_push(stack_t **stack, unsigned int line_num)
{
	int value = atoi(header.arg);

	if (!header.arg || !validate_integer(header.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		handle_error(stack, EXIT_FAILURE);
	}


	if (new_int_node(stack, value) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		handle_error(stack, EXIT_FAILURE);
	}
}

/**
 * validate_integer - Validates if a string represents an integer.
 * @str_val: The string to validate.
 * Return: 1 if the string represents an integer, 0 otherwise.
 */
int validate_integer(char *str_val)
{
	if (str_val == NULL || *str_val == '\0')
		return (0);

	if (*str_val == '-' || *str_val == '+')
		str_val++;

	while (*str_val != '\0')
	{
		if (*str_val < '0' || *str_val > '9')
			return (0);

		str_val++;
	}

	return (1);
}

/**
 * handle_error - Centralizes error handling.
 * @exit_code: Exit code for the program.
 * @stack: first arg
 */
void handle_error(stack_t **stack, int exit_code)
{
	free_stack(*stack);
	fclose(header.file);
	free(header.line);
	exit(exit_code);
}
