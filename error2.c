#include "monty.h"
/**
 * mul_error - prints mul error
 * @stack: pointer to stack
 * @line_number: line number
 */
void mul_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * mod_error - prints modulous error
 * @stack: pointer to stack
 * @line_number: line number
 */
void mod_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * pchar_error1 - prints pchar error
 * @stack: pointer to stack
 * @line_number: line number
 */
void pchar_error1(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * pchar_error2 - prints pchar error
 * @stack: pointer to stack
 * @line_number: line number
 */
void pchar_error2(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}
