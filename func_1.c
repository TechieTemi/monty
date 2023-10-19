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

/**
 * mod - divides second top element by top element of the stack
 * @line_num: line number
 * @stack: stack of ints
 */

void mod(stack_t **stack, unsigned int line_num)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		val.err_code = -1;
		p_error("", "can't mod, stack too short", *stack, line_num, "", "");
		return;
	}

	if ((*stack)->n == 0)
	{
		val.err_code = -1;
		p_error("", "division by zero", *stack, line_num, "", "");
		return;
	}

	n = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = n;
	pop(stack, line_num);
}

/**
 * rotl - swaps top two with the bottom
 * @line_num: line number
 * @stack: stack of ints
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return; /* Nothing to rotate if the stack is empty or has only one element*/
	}

	n = *stack;
	while (n->next != NULL)
	{
		n = n->next;
	}

	n->next = *stack;
	(*stack)->prev = n;
	*stack = (*stack)->next;
	n->next->next = NULL;

	(void)line_num;
}
