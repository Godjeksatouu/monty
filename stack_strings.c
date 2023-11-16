#include "monty.h"

/**
 * printAscii - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printAscii(stack_t **stack, unsigned int lineNumber)
{
	int asciiValue;

	if (stack == NULL || *stack == NULL)
		stringErr(11, lineNumber);

	asciiValue = (*stack)->n;
	if (asciiValue < 0 || asciiValue > 127)
		stringErr(10, lineNumber);
	printf("%c\n", asciiValue);
}

/**
 * printString - Prints a string.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void printString(stack_t **stack, __attribute__((unused))unsigned int lineNumber)
{
	int asciiValue;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		asciiValue = tmp->n;
		if (asciiValue <= 0 || asciiValue > 127)
			break;
		printf("%c", asciiValue);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotateLeft - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void rotateLeft(stack_t **stack, __attribute__((unused))unsigned int lineNumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotateRight - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void rotateRight(stack_t **stack, __attribute__((unused))unsigned int lineNumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
