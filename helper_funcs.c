#include "monty.h"

/**
 * _iswhitespace - check for whitespace
 * Return: 1 if only whitespace 0 if not only whitespace
 */
int _iswhitespace(void)
{
	int i, j;
	char *wsc = "\t\n\r "; /*white-space characters*/

	for (i = 0; global.lineptr[i] != '\0'; i++)
		for (j = 0; wsc[j] != '\0' && wsc[j] != global.lineptr[i]; j++)
			if (wsc[j] == '\n')
				return (0);
	return (1);
}

/**
 * free_stack - free a stack with single ptr reference
 * @stack: pointer to a stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

/**
 * exit_free - frees all possible allocs before exiting the program
 * @stack: pointer to a stack
 */
void exit_free(stack_t *stack)
{
	fclose(global.monty_stream);

	if (global.lineptr != NULL)
		free(global.lineptr);
	free(stack);
}
