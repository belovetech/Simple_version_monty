#include "monty.h"

void args_error()
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}

void file_error(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    fclose(global.monty_stream);
    exit(EXIT_FAILURE);
}

void push_error(stack_t *stack, int line_number)
{
    fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit_free(stack);
	exit(EXIT_FAILURE);
}

void opcode_error(stack_t **stack, int line_number, char *opcode)
{
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

void malloc_error(stack_t **stack)
{
    fprintf(stderr, "Error: malloc failed\n");
    exit_free(*stack);
    exit(EXIT_FAILURE);
}

void pint_error(stack_t **stack, int line_number)
{
    fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

void pop_error(stack_t **stack, int line_number)
{
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    exit_free(*stack);
	exit(EXIT_FAILURE);
}

void swap_error(stack_t **stack, int line_number)
{
    fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
    exit_free(*stack);
	exit(EXIT_FAILURE);
}

void add_error(stack_t **stack, int line_number)
{
    fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
    exit_free(*stack);
	exit(EXIT_FAILURE);
}

void sub_error(stack_t **stack, int line_number)
{
    fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
    exit_free(*stack);
	exit(EXIT_FAILURE);
}

void div_error1(stack_t **stack, int line_number)
{
    fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
    exit_free(*stack);
	exit(EXIT_FAILURE);
}

void div_error2(stack_t **stack, int line_number)
{
    fprintf(stderr, "L%u: division by zero\n", line_number);
    exit_free(*stack);
	exit(EXIT_FAILURE);
}

void mul_error(stack_t **stack, int line_number)
{
    fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
    exit_free(*stack);
	exit(EXIT_FAILURE);
}

void mod_error(stack_t **stack, int line_number)
{
    fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
    exit_free(*stack);
	exit(EXIT_FAILURE);
}

void pchar_error1(stack_t **stack, int line_number)
{
    fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
    exit_free(*stack);
	exit(EXIT_FAILURE);
}

void pchar_error2(stack_t **stack, int line_number)
{
    fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
    exit_free(*stack);
	exit(EXIT_FAILURE);
}