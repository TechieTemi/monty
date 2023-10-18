#include "monty.h"

/**
 * convert_string_to_int- convert string to int.
 * @string: error message
 * @line: line number
 * @token: opcode
 * @stack: stack of ints
 * Return: int
 */

int convert_string_to_int(char *string, int line, char *token, stack_t *stack)
{
	char *endpointer;
	long number;

	errno = 0; /* Reset errno before the call */
	number = strtol(string, &endpointer, 10);

	if (errno == ERANGE || number > INT_MAX || number < INT_MIN)
	{
		val.err_code = -1;
		p_error("", "usage: ", stack, line, token, " integer");
	}

	if (endpointer == string)
	{
		val.err_code = -1;
		p_error("", "usage: ", stack, line, token, " integer");
	}
	/* Check for trailing characters */
	while (*endpointer != '\0')
	{
		if (!isspace(*endpointer))
		{
			val.err_code = -1;
			p_error("", "usage: ", stack, line, token, " integer");
		}
		endpointer++;
	}

	val.data = (int)number;
	return (0);
}

/**
 * p_error - Print a string to the standard output stream.
 * @s: error header
 * @e: error message
 * @stk: stack to be freed before exiting
 * @line_num: line number
 * @tok: token
 * @t: extra
 */
void p_error(char *s, char *e, stack_t *stk, int line_num, char *tok, char *t)
{
	if (line_num > 0)
		fprintf(stderr, "L%d: %s%s%s\n", line_num, e, tok, t);
	else
		fprintf(stderr, "%s: %s%s\n", s, e, tok);
	free_stack(stk);
	if (val.err_code == -1)
		fclose(val.file);
	if (val.buf)
		free(val.buf);
	exit(EXIT_FAILURE);
}


/**
 * pall - prints all data in the stack
 * @line_num: line number
 * @stack: stack of ints
 */

void pall(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		(void)line_num;
		return;  /* Base case: Stack is empty, nothing to print.*/
	}

	printf("%d\n", (*stack)->n);  /* Print the top element of the stack.*/

	/* Recursively call pall on the,*/
	/*rest of the stack.*/
	pall(&((*stack)->next), line_num);
}



/**
 * pint - prints the last element of a list
 * @line_num: line number
 * @stack: stack of ints
 */

void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		val.err_code = -1;
		p_error("Error", "can't pint, stack empty", *stack, line_num, "", "");
	} else
	{
		printf("%d\n", (*stack)->n);
	}
}
