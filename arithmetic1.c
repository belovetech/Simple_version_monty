#include "monty.h"
/**
 * swap - swaps the first two element in the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int count = 0, swap;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	if (count < 2)
		swap_error(stack, line_number);
	else
	{
		temp = *stack;
		swap = temp->n;
		temp->n = temp->next->n;
		temp->next->n = swap;
	}
}

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Description: The result is stored in the second top element
 * of the stack, and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 */
void add(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
		add_error(stack, line_number);

	(*stack)->next->n = (*stack)->n + (*stack)->next->n;

	pop(stack, line_number);
}

/**
 * sub - subtracts the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Description: The result is stored in the second top element
 * of the stack, and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
		sub_error(stack, line_number);

	(*stack)->next->n =  (*stack)->next->n - (*stack)->n;

	pop(stack, line_number);
}
