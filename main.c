#include "monty.h"
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

	head_nodes.file = fopen(argv[1], "r");
	if (head_nodes.file == NULL)
	{
		fprintf(stderr, "ERORR opening file failed %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_reader(&stack);
	fclose(head_nodes.file);
	free(head_nodes.line);
	free_stack(stack);
	exit(EXIT_SUCCESS);
}
