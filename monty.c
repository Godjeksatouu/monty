#include "monty.h"

void free_stack(stack_t *stack);
int misc[] = {0, 0, 0};

/**
 * main - Runs Monty commands from a file given as a command-line argument.
 *
 * @argc: Number of arguments provided to the program.
 * @argv: Array holding command-line arguments.
 *
 * Return: Returns EXIT_SUCCESS if the program runs without issues;
 *         otherwise, an error code.
 */

int main(int argc, char **argv)
{
	FILE *monty_file;
	char *buffer = NULL;
	ssize_t len;
	size_t n;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	misc[MODE_IDX] = STAK_MODE;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	len = getline(&buffer, &n, monty_file);
	while (len != -1)
	{
		line_number++;
		proc_line(buffer, line_number, &stack);
		free(buffer);
		buffer = NULL;
		if (misc[ERROR_IDX] != 0)
		{
			free_stack(stack);
			fclose(monty_file);
			exit(EXIT_FAILURE);
		}
		len = getline(&buffer, &n, monty_file);
	}
	free(buffer);
	free_stack(stack);
	fclose(monty_file);
	return (EXIT_SUCCESS);
}

/**
 * free_stack - Frees up memory used by the stack.
 *
 * @stack: Pointer to the start of the stack.
 *
 * Returns: Nothing.
 */


void free_stack(stack_t *stack)
{
	stack_t *next;

	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}
