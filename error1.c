#include "monty.h"
/**
 * args_error - args error
 */
void args_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - args error
 * @filename: filename
 */
void file_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	fclose(global.monty_stream);
	exit(EXIT_FAILURE);
}

/**
 * push_error - prints push error
 * @stack: pointer to stack
 * @line_number: line number
 */
void push_error(stack_t *stack, int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit_free(stack);
	exit(EXIT_FAILURE);
}

/**
 * opcode_error - prints opcodes error
 * @stack: pointer to stack
 * @line_number: line number
 * @opcode: opcodes
 */
void opcode_error(stack_t **stack, int line_number, char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc error
 * @stack: pointer to stack
 */
void malloc_error(stack_t **stack)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

