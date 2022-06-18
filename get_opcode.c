#include "monty.h"
/**
 * opcmp - compares opcode and link it with its corresponding function
 * @stack: pointer to the stack
 * @line_number: line number
 * @opcode: operation codes
 */
void opcmp(stack_t **stack, int line_number, char *opcode)
{
	int i = 0;
	instruction_t opc[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	while (opc[i].opcode != NULL)
	{
		if (strcmp(opcode, opc[i].opcode) == 0)
		{
			opc[i].f(stack, line_number);
			return;
		}
		i++;
	}
	opcode_error(stack, line_number, opcode);
}
