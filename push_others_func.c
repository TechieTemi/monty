#include "monty.h"

/**
 * free_stack - frees a doubly liked list.
 * @stack: poiter to the list head.
 */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *tmp;

		if (stack == NULL)
			return;
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}


/**
 * push - adds data to stack
 * @line_num: line number
 * @stack: stack of ints
 */

void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new;

	if (val.chk != 0)
	{
		val.err_code = -1;
		p_error("", "usage: ", *stack, line_num, "push ", "integer");
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		val.err_code = -1;
		p_error("Error", "malloc", *stack, -1, " ", "failed");
	}
	new->n = val.data;

	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return;
	}

	new->next = *stack;
	(*stack)->prev = new;
	(*stack)->prev = NULL;
	*stack = new;
}



/**
 * pop - pops top element of the stack
 * @line_num: line number
 * @stack: stack of ints
 */

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	else
	{
		val.err_code = -1;
		p_error("", "can't pop an empty stack", *stack, line_num, "", "");
	}
}



/**
 * swap - swaps top two on the stack
 * @line_num: line number
 * @stack: stack of ints
 */

void swap(stack_t **stack, unsigned int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		val.err_code = -1;
		p_error("", "can't swap, stack too short", *stack, line_num, "", "");
	}
	else
	{
		stack_t *current = *stack;
		stack_t *next_node = (*stack)->next;

		int temp = current->n;

		current->n = next_node->n;
		next_node->n = temp;
	}
}

