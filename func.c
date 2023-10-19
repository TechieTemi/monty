#include "monty.h"

/**
 * add - adds top two element of the stack
 * @line_num: line number
 * @stack: stack of ints
 */

void add(stack_t **stack, unsigned int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		val.err_code = -1;
		p_error("", "can't add, stack too short", *stack, line_num, "", "");
	}
	else
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_num);
	}
}


/**
 * nop - No operation
 * @stack: stack of ints (unused)
 * @line_num: line number (unused)
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

