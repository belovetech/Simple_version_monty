#include "monty.h"
/**
 * div_error1 - prints div error
 * @stack: pointer to stack
 * @line_number: line number
 */
void div_error1(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * div_error2 - prints div error
 * @stack: pointer to stack
 * @line_number: line number
 */
void div_error2(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}
