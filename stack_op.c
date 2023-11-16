#include "monty.h"

/**
 * multiplyNodes - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void multiplyNodes(stack_t **stack, unsigned int lineNumber)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreErr(8, lineNumber, "mul");

	(*stack) = (*stack)->next;
	product = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = product;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * moduloNodes - Computes the remainder of the division of the top two elements.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @lineNumber: Integer representing the line number of the opcode.
 */
void moduloNodes(stack_t **stack, unsigned int lineNumber)
{
	int remainder;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreErr(8, lineNumber, "mod");

	if ((*stack)->n == 0)
		moreErr(9, lineNumber);

	(*stack) = (*stack)->next;
	remainder = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = remainder;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

