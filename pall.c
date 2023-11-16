#include "monty.h"

/**
*printStack - Prints all elements of the stack.
*@stackHead: Pointer to the head of the stack.
*@lineNumber: Not used.
*Return: No return value.
*/
void printStack(stack_t **stackHead, unsigned int lineNumber)
{
stack_t *currentNode;
(void)lineNumber;

currentNode = *stackHead;

if (currentNode == NULL)
return;

for (; currentNode != NULL; currentNode = currentNode->next)
{
printf("%d\n", currentNode->n);
}
}
