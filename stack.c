#include "monty.h"

/**
 * _stack - Sets the global variable to 0
 * @stack: Pointer to the top of the stack (unused)
 * @encounter: The line number where the instruction appears (unused)
 *
 * Description:
 * This function sets the global variable bus.lifi to 0. It takes two
 * parameters: a pointer to the top of the stack and the line number where
 * the instruction appears, but these parameters are unused.
 */
void _stack(stack_t **stack, unsigned int encounter)
{
	(void)stack;
	(void)encounter;
	header.help = 0;
}
