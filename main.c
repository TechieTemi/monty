#include "monty.h"

void t(void);
val_t val;

/**
 * exec_ops - find appriopriate funcs
 * @buffer: line buffer
 * @ops: Array containing funcs
 * @line_num: line number
 * @stack: stack of ints
 */
void exec_ops(char *buffer, instruction_t ops[], int line_num, stack_t **stack)
{
	char *token1, *token2 = NULL, *delim = " \n\t\r";
	int i;

	val.chk = -1;
	token1 = strtok(buffer, delim);
	if (token1 && token1[0] == '#')
		;
	else if (token1)
	{
		token2 = strtok(NULL, delim);
		if (token2 != NULL && strcmp(token1, "push") == 0)
		{
			val.chk = convert_string_to_int(token2, line_num, token1, *stack);
		}
		/* looping through array of funcs */
		i = 0;
		while (ops[i].opcode)
		{
			if (strcmp(ops[i].opcode, token1) == 0)
			{
				ops[i].f(stack, line_num);
				break;
			}
			i++;
		}
		if (ops[i].opcode == NULL)
		{
			val.err_code = -1;
			p_error("", "unknown instruction ", *stack, line_num, token1, "");
		}
	}
}


/**
 * pstr - prints ascii value of the n member of the stack list
 * @stack: pointer to the topmost element of the stack
 * @line_number: line containing pstr opcode
 * Return: nothing
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	for (tmp = *stack; tmp && (tmp->n > 0 && tmp->n < 128); tmp = tmp->next)
	{
		putchar(tmp->n);
	}

	putchar('\n');
}


/**
 * pchar - prints ascii value at top of the stack
 * @stack: pointer to the topmost element of the stack
 * @line_num: line containing pchar opcode
 * Return: nothing
 */

void pchar(stack_t **stack, unsigned int line_num)
{
	char *msg = "can't pchar, value out of range";

	if (*stack == NULL || (*stack)->n <= 0 || (*stack)->n >= 128)
	{
		val.err_code = -1;
		if (*stack == NULL)
		{
			p_error("", "can't pchar, stack empty", *stack, line_num, "", "");
		} else
		{
			p_error("", msg, *stack, line_num, "", "");
		}
	}
	else
	{
		printf("%c\n", (*stack)->n);
	}
}


/**
 * main - Entry point of the program
 * @ac: The number of command-line arguments
 * @av: Array containing the command-line arguments
 *
 * Return: Exit status of the program
 */
int main(int ac, char **av)
{
	char *buffer = NULL;
	size_t size = 0;
	FILE *file;
	int num_line = 0;
	stack_t *stack = NULL;
	instruction_t ops[] = {
		{"pint", pint},
		{"pall", pall},
		{"pstr", pstr},
		{"pchar", pchar},
		{"push", push},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_},
		{NULL, NULL}
	};

	val.err_code = 0;
	val.buf = NULL;
	val.file = NULL;
	if (ac != 2)
		p_error("USAGE", "monty file", stack, -1, "", "");
	file = fopen(av[1], "r");
	if (!file)
	{
		p_error("Error", "Can't open file ", stack, -1, av[1], "");
	}
	val.file = file;
	while (getline(&buffer, &size, file) != -1)
	{
		val.buf = buffer;
		num_line++;
		exec_ops(buffer, ops, num_line, &stack);
	}
	fclose(file);
	free_stack(stack);
	free(buffer);
	exit(EXIT_SUCCESS);
}
