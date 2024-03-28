#include "monty.h"
#include <stdio.h>
/**
 * line_reader - reads lines from the input file and executes opcodes
 * @stack: pointer to the top of the stack
 *
 * Description: This function reads lines from the input file, tokenizes
 * each line to extract the opcode and its argument (if any), and then
 * calls the `executable` function to execute the opcode with the
 * corresponding argument (if any).
 */
void line_reader(stack_t **stack)
{
	char line[1024];
	unsigned int line_num = 0;
	size_t len = strlen(line);
	char *opcode = strtok(line, " \t\r\n\a");

	while (fgets(line, sizeof(line), header.file) != NULL)
	{
		line_num++;

		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}

		header.arg = strtok(NULL, " \n\t");
		if (opcode == NULL || *opcode == '#')
		{
			continue;
			}
		executable(opcode, stack, line_num);
	}
}
