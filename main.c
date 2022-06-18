#define  _GNU_SOURCE
#include "monty.h"

#define  _POSIX_C_SOURCE 200809L
#define BUFSIZE 1024

/**
 * main - Gets file, read line of the file and parse it
 * @argc: arguement count
 * @argv: arguement vector
 * Return: 0 always (success)
 */

int main(int argc, char **argv)
{
	char opcode[6] = {0}, end[BUFSIZE] = {0};
	stack_t *stack =  NULL;
	ssize_t nread;
	size_t len = 0;
	unsigned int line_number = 0;
	int matches;

	/* too many or few args to monty interpreter */
	if (argc != 2)
		args_error();

	global.monty_stream = NULL;
	global.monty_stream = fopen(argv[1], "r");

	/* if file can't open */
	if (global.monty_stream == NULL)
		file_error(argv[1]);

	global.lineptr = NULL;
	while ((nread = getline(&global.lineptr, &len, global.monty_stream) != -1))
	{
		line_number++;
		if (!_iswhitespace())
		{
			matches = sscanf(global.lineptr, "%s%d%s", opcode, &global.data, end);
			if (matches != 2 && strcmp(opcode, "push") == 0)
				push_error(stack, line_number);

			if (opcode != NULL && opcode[0] != '#')
				opcmp(&stack, line_number, opcode);
		}
		free(global.lineptr);
		global.lineptr = NULL;
	}
	exit_free(stack);
	return (0);
}
