#include "monty.h"

/**
 * mul - multiplies top element by second top element of the stack
 * @line_num: line number
 * @stack: stack of ints
 */

void mul(stack_t **stack, unsigned int line_num)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		val.err_code = -1;
		p_error("", "can't mul, stack too short", *stack, line_num, "", "");
		return;
	}

	n = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = n;
	pop(stack, line_num);
}
