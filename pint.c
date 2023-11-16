#include "monty.h"

/**
*printTopElement - Prints the top element of the stack.
*@stackHead: Pointer to the head of the stack.
*@lineNumber: Line number in the file.
*Return: No return value.
*/
void printTopElement(stack_t **stackHead, unsigned int lineNumber)
{
while (*stackHead == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", lineNumber);
fclose(bus.file);
free(bus.content);
freeStack(*stackHead);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stackHead)->n);
}

