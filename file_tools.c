#include "monty.h"

/**
*openAndReadFile - Opens and reads a file.
*@filePath: The path of the file.
*Return: void
*/
void openAndReadFile(char *filePath)
{
FILE *fileDescriptor = fopen(filePath, "r");

if (filePath == NULL || fileDescriptor == NULL)
handleError(2, filePath);

readFile(fileDescriptor);
fclose(fileDescriptor);
}

/**
*readFile - Reads the content of a file line by line.
*@fileDescriptor: Pointer to the file descriptor.
*Return: void
*/
void readFile(FILE *fileDescriptor)
{
int lineNumber, format = 0;
char *buffer = NULL;
size_t bufferSize = 0;

while (getline(&buffer, &bufferSize, fileDescriptor) != -1)
{
format = parseLine(buffer, lineNumber, format);
lineNumber++;
}

free(buffer);
}

/**
*parseLine - Separates each line into tokens to determine
*which function to call.
*@buffer: Line from the file.
*@lineNumber: Line number.
*@format: Storage format. If 0, nodes will be entered as a stack.
*If 1, nodes will be entered as a queue.
*Return: Returns 0 if the opcode is stack. 1 if queue.
*/
int parseLine(char *buffer, int lineNumber, int format)
{
char *opcode, *value;
const char *delimiter = "\n ";

if (buffer == NULL)
handleError(4);

opcode = strtok(buffer, delimiter);
if (opcode == NULL)
return format;
value = strtok(NULL, delimiter);

if (strcmp(opcode, "stack") == 0)
return 0;
if (strcmp(opcode, "queue") == 0)
return 1;

findFunction(opcode, value, lineNumber, format);
return format;
}

/**
*findFunction - Find the appropriate function for the opcode.
*@opcode: Opcode.
*@value: Argument of opcode.
*@lineNumber: Line number.
*@format: Storage format. If 0, nodes will be entered as a stack.
*If 1, nodes will be entered as a queue.
*Return: void
*/
void findFunction(char *opcode, char *value, int lineNumber, int format)
{
int flag;
int i;

instruction_t functionList[] = {
{"push", pushToStack},
{"pall", printStack},
{"pint", printTop},
{"pop", popTop},
{"nop", nop},
{"swap", swapNodes},
{"add", addNodes},
{"sub", subNodes},
{"div", divNodes},
{"mul", mulNodes},
{"mod", modNodes},
{"pchar", printChar},
{"pstr", printStr},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}
    };

if (opcode[0] == '#')
return;

for (flag = 1, i = 0; functionList[i].opcode != NULL; i++)
{
if (strcmp(opcode, functionList[i].opcode) == 0)
{
callFunction(functionList[i].f, opcode, value, lineNumber, format);
flag = 0;
}
}
if (flag == 1)
handleError(3, lineNumber, opcode);
}

/**
*callFunction - Calls the required function.
*@function: Pointer to the function that is about to be called.
*@op: String representing the opcode.
*@val: String representing a numeric value.
*@ln: Line number for the instruction.
*@format: Format specifier. If 0, nodes will be entered as a stack.
*If 1, nodes will be entered as a queue.
*/
void callFunction(op_func function, char *op, char *val, int ln, int format)
{
stack_t *node;
int flag;
int i;

flag = 1;
if (strcmp(op, "push") == 0)
{
if (val != NULL && val[0] == '-')
{
val = val + 1;
flag = -1;
}
if (val == NULL)
handleError(5, ln);
for (i = 0; val[i] != '\0'; i++)
{
if (isdigit(val[i]) == 0)
handleError(5, ln);
}
node = createNode(atoi(val) * flag);
if (format == 0)
function(&node, ln);
if (format == 1)
addToQueue(&node, ln);
}
else
function(&head, ln);
}

