#include "monty.h"
head header = {NULL, NULL, NULL, 0};
/**
 * main - monty main function
 * @argc: 1stargument
 * @argv: 2ndargument
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	header.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		content = (char *)malloc(size * sizeof(char));
		if (!content)
		{
			fprintf(stderr, "Error: Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}

		if (fgets(content, size, file) == NULL)
		{
			free(content);
			break;
		}
		counter++;
		executable(content, &stack, counter, file);
		free(content);
	}

	free_stack(stack);
	fclose(file);
return (0);
}
