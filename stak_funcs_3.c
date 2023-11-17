#include "monty.h"

/**
 * mul - Multiplies the top two elements of the stack.
 *       Stores the result at the top, making the stack shorter.
 *       Exits with an error message and EXIT_FAILURE if an issue occurs.
 *
 * @stack: Pointer to the stack's top.
 * @line_number: Line number of where the mul opcode is in the file.
 *
 * Return: None.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}
	res = (*stack)->n * (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = res;
}

/**
 * mod - Computes the remainder of the second element divided by the first.
 *       Stores the result at the top, making the stack shorter.
 *       Exits with an error message and EXIT_FAILURE if an issue occurs.
 *
 * @stack: Pointer to the stack's top.
 * @line_number: Line number where the mod opcode is in the file.
 *
 * Return: None.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}

	res = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = res;
}

/**
 * pchar - Prints the character equivalent of the integer at the top of the stack.
 *         Exits with an error message and EXIT_FAILURE if an issue occurs.
 *
 * @stack: Pointer to the stack's top.
 * @line_number: Line number of where the pchar opcode is in the file.
 *
 * Return: None.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		misc[ERROR_IDX] = 1;
		return;
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints stack elements as ASCII characters until the stack is empty,
 *        an element is 0, or an invalid ASCII value is encountered. Prints a
 *        newline regardless.
 *
 * @stack: Pointer to the stack's top.
 * @line_number: Line number where the pstr opcode is in the file.
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int ascii;
	(void) line_number;

	if (stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			ascii = current->n;
			if (ascii != 0 && ascii > 0 && ascii <= 127)
				putchar(ascii);
			else
				break;
			current = current->next;
		}
	}
	putchar('\n');
}
