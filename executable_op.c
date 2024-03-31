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
int executable (char *content, stack_t **stack, unsigned int counter, FILE *file)
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
	

	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	header.arg = strtok(NULL, " \n\t");
	while (instructions[i].opcode && op)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
		{	instructions[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && instructions[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
