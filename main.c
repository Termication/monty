#include "monty.h"
head header;
/**
 * main - monty main function
 * @argc: 1stargument
 * @argv: 2ndargument
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	header.file = fopen(argv[1], "r");
	if (header.file == NULL)
	{
		fprintf(stderr, "error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_reader(&stack);
	fclose(header.file);
	free(header.line);
	free_stack(stack);
	exit(EXIT_SUCCESS);
}
