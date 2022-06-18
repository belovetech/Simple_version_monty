#include "monty.h"

void pchar(stack_t **stack, unsigned int line_number)
{
    int first;

    if (*stack == NULL)
        pchar_error1(stack, line_number);

    first = (*stack)->n;
    if (first >= 0 && first <= 127)
        fprintf(stdout, "%c\n", first);
    else
        pchar_error2(stack, line_number);
}

void pstr(stack_t **stack, unsigned int line_number)
{
    (void) line_number;
    stack_t *temp = *stack;

    if (*stack == NULL)
        fprintf(stdout, "\n");
    else
    {
        while (temp != NULL)
        {
            if (temp->n > 0 && temp->n <= 127)
                fprintf(stdout, "%c", temp->n);
            else
                break;
            temp = temp->next;
        }
    }
    fprintf(stdout, "\n");
}

void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *last, *temp = *stack;
    int first = (*stack)->n;

    last = malloc(sizeof(stack_t));
    if (last == NULL)
        malloc_error(stack);

    while (temp->next != NULL)
        temp = temp->next;

    last->n = first;
    last->prev = temp;
    last->next = NULL;
    temp->next = last;

    pop(stack, line_number);
}

void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void) line_number;

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    temp->next = *stack;
    (*stack)->prev = temp;
    temp->prev = NULL;
    (*stack) = temp;
}
