#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_s
{
	int n;
	struct stack_s *next;
} stack_t;

typedef struct interpreter_s
{
	FILE *file;
	char *content;
	stack_t *stack;
	unsigned int line_number;
} interpreter_t;


int monty_interpreter(int argument_count, char *argument_values[]);
void execute(char *instruction, stack_t **stack, unsigned int line_number, FILE *file_pointer);
int is_valid_argument(char *argument);
void push(stack_t **stack, int value);
void pall(stack_t *stack);
void free_stack(stack_t *stack);
void pint(stack_t *stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
