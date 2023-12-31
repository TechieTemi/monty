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


/**
 * sub - sbtracts top element from second top element of the stack
 * @line_num: line number
 * @stack: stack of ints
 */

void sub(stack_t **stack, unsigned int line_num)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		val.err_code = -1;
		p_error("", "can't sub, stack too short", *stack, line_num, "", "");
		return;
	}

	n = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = n;
	pop(stack, line_num);
}

/**
 * div_ - divides second top element by top element of the stack
 * @line_num: line number
 * @stack: stack of ints
 */

void div_(stack_t **stack, unsigned int line_num)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		val.err_code = -1;
		p_error("", "can't div, stack too short", *stack, line_num, "", "");
		return;
	}

	if ((*stack)->n == 0)
	{
		val.err_code = -1;
		p_error("", "division by zero", *stack, line_num, "", "");
		return;
	}

	n = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = n;
	pop(stack, line_num);
}
