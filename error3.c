#include "monty.h"
/**
 * pint_error - prints pint error
 * @stack: pointer to stack
 * @line_number: line number
 */
void pint_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * pop_error - prints pop error
 * @stack: pointer to stack
 * @line_number: line number
 */
void pop_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * swap_error - prints swap error
 * @stack: pointer to stack
 * @line_number: line number
 */
void swap_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * add_error - prints add error
 * @stack: pointer to stack
 * @line_number: line number
 */
void add_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * sub_error - prints sub error
 * @stack: pointer to stack
 * @line_number: line number
 */
void sub_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}
