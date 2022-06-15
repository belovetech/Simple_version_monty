#include "monty.h"

int is_line_empty(char *line, char *delimeters)
{
    int i, j;
    
    for (i = 0; line[i]; i++)
    {
        for (j = 0; delimeters[j]; j++)
        {
            if (line[i] == delimeters[j])
                break;
        }
        if (delimeters[j] == '\0')
            return (0);
    }
    return (1);
}


int monty(FILE *bytecodes)
{
    stack_t *stack = NULL, *line = NULL;
    unsigned int line_number = 0;
    size_t len = 0, status;
    void (*opcmd)(stack_t**, unsigned int);
    
    
    if (create_stack(&stack) == EXIT_FAILURE)
        return (EXIT_FAILURE);
        
    while (getline(&line, &len, bytecodes) != -1)
    {
        line_number++;
        tokens = strtow(line, DELIMETERS);
        
        if (tokens == NULL)
        {
           if (is_line_empty(line, DELIMETERS))
                continue;
            free_stack(&stack);
            write(2, "Error: malloc failed", 20);
            return (EXIT_FAILURE);
        }
        else if (tokens[0][0] == '#')
        {
            free_token();
            continue;
        }
        opcmd = get_op_func(tokens[0]);
        if (opcmd == NULL)
        {
            free_stack(&stack);
//  TODO           write(2, "L<line_number>: unknown instruction <opcode>")
            free_token();
            break;

        }
    }
    
}