#include "monty.h"

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

void add(stack_t **stack, unsigned int line_number)
{
    if ((*stack) == NULL || (*stack)->next == NULL)
        add_error(stack, line_number);

    (*stack)->next->n = (*stack)->n + (*stack)->next->n;

    pop(stack, line_number);
}

void sub(stack_t **stack, unsigned int line_number)
{
    if ((*stack) == NULL || (*stack)->next == NULL)
        sub_error(stack, line_number);

    (*stack)->next->n =  (*stack)->next->n - (*stack)->n;

    pop(stack, line_number);
}

void _div(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->n == 0)
        div_error2(stack, line_number);

    if ((*stack) == NULL || (*stack)->next == NULL)
        div_error1(stack, line_number);

    (*stack)->next->n =  (*stack)->next->n / (*stack)->n;

    pop(stack, line_number);
}

void mul(stack_t **stack, unsigned int line_number)
{
    if ((*stack) == NULL || (*stack)->next == NULL)
        mul_error(stack, line_number);

    (*stack)->next->n = (*stack)->n * (*stack)->next->n;

    pop(stack, line_number);
}

void mod(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->n == 0)
        div_error2(stack, line_number);

    if ((*stack) == NULL || (*stack)->next == NULL)
        mod_error(stack, line_number);

    (*stack)->next->n =  (*stack)->next->n % (*stack)->n;

    pop(stack, line_number);
}
