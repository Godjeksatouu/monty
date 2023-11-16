#include "monty.h"

/**
 *pushNode - Adds a node to the stack.
 *@stackHead: Pointer to the head of the stack.
 *@lineNumber: Line number in the file.
 *Return: No return value.
 */
void pushNode(stack_t **stackHead, unsigned int lineNumber)
{
int value, index = 0, invalidCharFlag = 0;

if (bus.arg)
{
if (bus.arg[0] == '-')
index++;

while (bus.arg[index] != '\0')
{
if (bus.arg[index] > '9' || bus.arg[index] < '0')
invalidCharFlag = 1;
index++;
}

if (invalidCharFlag)
{
fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
fclose(bus.file);
free(bus.content);
freeStack(*stackHead);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
fclose(bus.file);
free(bus.content);
freeStack(*stackHead);
exit(EXIT_FAILURE);
}

value = atoi(bus.arg);

if (bus.lifi == 0)
addNodeToStack(stackHead, value);
else
addNodeToQueue(stackHead, value);
}

