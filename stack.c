#include "monty.h"


int create_stack(stack_t **stack)
{
    stack_t *new_stack;

    new_stack =  malloc(sizeof(stack_t));
    if (new_stack == NULL)
    {
        write(2, "Error: malloc failed", 20);
        return (EXIT_FAILURE);
    }

    new_stack->n = STACK; // STACK == 1
    new_stack->prev = NULL;
    new_stack->next = NULL;

    *stack = new_stack;
    return (EXIT_SUCCESS);
}


void free_stack(stack_t **stack)
{
    stack_t *temp = *stack;
    
    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}
