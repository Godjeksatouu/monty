#include "monty.h"
stack_t *head = NULL;

/**
*main - Entry point of the program.
*@argc: Number of command-line arguments.
*@argv: Array of command-line argument strings.
*Return: Always returns 0.
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	freeNodes();
	return (0);
}

/**
*createNode - Creates a new node for the stack.
*@n: Number to be stored in the new node.
*Return: On success, returns a pointer to the new node, otherwise returns NULL.
*/
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * freeNodes - Frees all nodes in the stack.
 */
void freeNodes(void)
{
	stack_t *currentNode;

	if (stack_head == NULL)
	return;

	for (currentNode = stack_head; currentNode != NULL; )
	{
	stack_t *temp = currentNode;
	currentNode = currentNode->next;
	free(temp);
	}
}

/**
*addToQueue - Adds a new node to the end of the stack (queue).
*@newNode: Pointer to the new node to be added.
*@ln: Line number of the opcode.
*/
void addToQueue(stack_t **newNode, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (newNode == NULL || *newNode == NULL)
	exit(EXIT_FAILURE);

	if (stack_head == NULL)
	{
	stack_head = *newNode;
	return;
	}

	tmp = stack_head;
	while (tmp->next != NULL)
	tmp = tmp->next;

	tmp->next = *newNode;
	(*newNode)->prev = tmp;
}

