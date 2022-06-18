#include "monty.h"
/**
 * _div - divides the second top element of the stack by the
 * top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Description: The result is stored in the second top element
 * of the stack, and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->n == 0)
		div_error2(stack, line_number);

	if ((*stack) == NULL || (*stack)->next == NULL)
		div_error1(stack, line_number);

	(*stack)->next->n =  (*stack)->next->n / (*stack)->n;

	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack by the
 * top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
		mul_error(stack, line_number);

	(*stack)->next->n = (*stack)->n * (*stack)->next->n;

	pop(stack, line_number);
}

/**
 * mod - divides computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->n == 0)
		div_error2(stack, line_number);

	if ((*stack) == NULL || (*stack)->next == NULL)
		mod_error(stack, line_number);

	(*stack)->next->n =  (*stack)->next->n % (*stack)->n;

	pop(stack, line_number);
}
