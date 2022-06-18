#include "monty.h"
/**
 * push - pushes data to the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = NULL;
	(void) line_number;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		malloc_error(stack);

	newNode->n = global.data;
	newNode->prev = NULL;
	if (*stack == NULL)
	{
		newNode->next = NULL;
		*stack = newNode;
	}
	else
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
		*stack = newNode;
	}
}

/**
 * pall - prints all data in the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (*stack == NULL)
		return;

	temp = *stack;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints first data in the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		pint_error(stack, line_number);
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop - removes the first data in the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
		pop_error(stack, line_number);

	if (temp->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * nop - prints nothing
 * @stack: pointer to the stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
