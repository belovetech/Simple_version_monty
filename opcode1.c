#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *newNode;
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

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    (void) line_number;
    if (*stack == NULL)
        return;
    else
    {
        temp = *stack;
        while (temp != NULL)
        {
            printf("%d\n", temp->n);
            temp = temp->next;
        }
    }
}


void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
        pint_error(stack, line_number);
    printf("%d\n", (*stack)->n);
}


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

void nop(stack_t **stack, unsigned int line_number)
{
   (void) stack;
   (void) line_number;
}

