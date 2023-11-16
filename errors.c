#include "monty.h"

/**
*handleError - Prints appropriate error messages based on the error code.
*@errorCode: Error codes:
*(1) => No file or more than one file provided.
*(2) => Unable to open or read the file.
*(3) => Invalid instruction in the file.
*(4) => Memory allocation failure.
*(5) => "push" instruction with non-integer parameter.
*/
void handleError(int errorCode, ...)
{
va_list args;
char *operation;
int lineNumber;

va_start(args, errorCode);
	switch (errorCode)
{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
	break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
	break;
	case 3:
		lineNumber = va_arg(args, int);
		operation = va_arg(args, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, operation);
	break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
	break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
	break;
	default:
	break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
*handleMoreError - Handles additional errors.
*@errorCode: Error codes:
*(6) => Empty stack for pint.
*(7) => Empty stack for pop.
*(8) => Stack too short for operation.
*(9) => Division by zero.
*/
void handleMoreError(int errorCode, ...)
{
va_list args;
char *operation;
int lineNumber;

		va_start(args, errorCode);
	switch (errorCode)
	{
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
	break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
	break;
	case 8:
		lineNumber = va_arg(args, unsigned int);
		operation = va_arg(args, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", lineNumber, operation);
	break;
	case 9:
		fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
	break;
	default:
	break;
	}
freeNodes();
exit(EXIT_FAILURE);
}

/**
*handleStringError - Handles string-related errors.
*@errorCode: Error codes:
*(10) => The number inside a node is outside ASCII bounds.
*(11) => The stack is empty.
*/
void handleStringError(int errorCode, ...)
{
va_list args;
int lineNumber;

va_start(args, errorCode);
lineNumber = va_arg(args, int);
	switch (errorCode)
	{
	case 10:
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
	break;
	case 11:
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
	break;
	default:
	break;
	}
freeNodes();
exit(EXIT_FAILURE);
}

