#include "monty.h"


int main(int argc, char *argv[])
{
     FILE *bytecodes = NULL;
     size_t status;
    
    if (argc != 2)
    {
     printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    
    bytecodes = fopen(argv[1], 'r');
    
    if (bytecode == NULL)
    {
        write(2, "Error: Can't open file <file>", 60);
        exit(EXIT_FAILURE);
    }
    
    status = monty(bytescodes);
    
    fclose(bytecodes);
    
    return (0);
}