#include "monty.h"

/**
*swapTopTwoElements - Swaps the top two elements of the stack.
*@stackHead: Pointer to the head of the stack.
*@lineNumber: Line number in the file.
*Return: No return value.
*/
void swapTopTwoElements(stack_t **stackHead, unsigned int lineNumber)
{
stack_t *currentNode;
int stackLength = 0, temp;

currentNode = *stackHead;

for (; currentNode != NULL; currentNode = currentNode->next, stackLength++)
;

if (stackLength < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
fclose(bus.file);
free(bus.content);
freeStack(*stackHead);
exit(EXIT_FAILURE);
}

currentNode = *stackHead;
temp = currentNode->n;
currentNode->n = currentNode->next->n;
currentNode->next->n = temp;
}

