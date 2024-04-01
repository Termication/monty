#include "monty.h"
/**
 * _queue - Sets the global variable header.help to 1
 * @stack: Pointer to the top of the stack (unused)
 * @encounter: The line number where the instruction appears (unused)
 *
 * Description:
 * This function sets the global variable header.help to 1. It takes two
 * parameters: a pointer to the top of the stack and the line number where
 * the instruction appears, but these parameters are unused.
 */
void _queue(stack_t **stack, unsigned int encounter)
{
	(void)stack;
	(void)encounter;
	header.help = 1;
}
