#include "monty.h"

/**
*popTopElement - Removes the top element from the stack.
*@stackHead: Pointer to the head of the stack.
*@lineNumber: Line number in the file.
*Return: No return value.
*/
void popTopElement(stack_t **stackHead, unsigned int lineNumber)
{
stack_t *currentNode;

while (*stackHead == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", lineNumber);
fclose(bus.file);
free(bus.content);
freeStack(*stackHead);
exit(EXIT_FAILURE);
}

currentNode = *stackHead;
*stackHead = currentNode->next;
free(currentNode);
}

