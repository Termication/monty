#include "monty.h"
/**
 * executable - executes an opcode
 * @arg: opcode to execute
 * @stack: pointer to the top of the stack
 * @encounter: line number where the operation is encountered
 *
 * Description: This function executes the specified opcode. It searches
 * through an array of instruction structures to find a matching opcode,
 * and if found, calls the corresponding function pointer with the given
 * stack and encounter parameters.
 */
void executable(char *arg, stack_t **stack, unsigned int encounter)
{
	instruction_t instructions[] = {
		{"push", opcode_push},
		{"pall", print_stack},
		{"pint", pint_int},
		{"pop", the_pop_op},
		{"swap", swap_opcode},
		{"nop", nop_opcode},
		{NULL, NULL}
	};
	int index;

	for (index = 0; instructions[index].opcode != NULL; index++)
	{
		if (strcmp(arg, instructions[index].opcode) == 0)
		{
			instructions[index].f(stack, encounter);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", encounter, arg);
	free_stack(*stack);
	fclose(header.file);
	free(header.line);
	exit(EXIT_FAILURE);
}
