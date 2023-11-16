#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern stack_t *stack_head;
typedef void (*operation_function)(stack_t **, unsigned int);

/* File operations */
void openFile(char *filename);
int parseLine(char *lineBuffer, int lineNumber, int format);
void readFile(FILE *file);
int countChars(FILE *file);
void findFunction(char *str1, char *str2, int num1, int num2);

/* Stack operations */
stack_t *createNode(int value);
void freeNodes(void);
void printStack(stack_t **stack, unsigned int size);
void addToStack(stack_t **stack, unsigned int value);
void addToQueue(stack_t **stack, unsigned int value);

void callFunction(operation_function, char *str1, char *str2, int num1, int num2);

void printTop(stack_t **stack, unsigned int index);
void popTop(stack_t **stack, unsigned int index);
void noOperation(stack_t **stack, unsigned int index);
void swapStackNodes(stack_t **stack, unsigned int index);

/* Math operations with nodes */
void addNodes(stack_t **stack, unsigned int index);
void subtractNodes(stack_t **stack, unsigned int index);
void divideNodes(stack_t **stack, unsigned int index);
void multiplyNodes(stack_t **stack, unsigned int index);
void moduloNodes(stack_t **stack, unsigned int index);

/* String operations */
void printCharacter(stack_t **stack, unsigned int index);
void printString(stack_t **stack, unsigned int index);
void rotateLeft(stack_t **stack, unsigned int index);

/* Error handling */
void handleError(int errorCode, ...);
void handleMoreError(int errorCode, ...);
void handleStringError(int errorCode, ...);
void rotateRight(stack_t **stack, unsigned int index);

#endif

