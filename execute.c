#include "monty.h"
#include <ctype.h>

/**
 * execute - Execute Monty bytecode instructions
 * @instruction: Monty bytecode instruction
 * @stack: Pointer to the stack
 * @line_number: Current line number in the bytecode file
 * @file_pointer: Pointer to the bytecode file
 */
void execute(char *instruction, stack_t **stack,
		unsigned int line_number, FILE *file_pointer)
{
	char *opcode, *argument;

	opcode = strtok(instruction, " \t\n");

	if (opcode == NULL || opcode[0] == '#')
		return;

	argument = strtok(NULL, " \t\n");

	if (strcmp(opcode, "push") == 0)
	{
		if (argument == NULL || !is_valid_argument(argument))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			fclose(file_pointer);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}

		push(stack, atoi(argument));

	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(*stack);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		fclose(file_pointer);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_valid_argument - Check if the argument is a valid integer
 * @argument: Argument to check
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_argument(char *argument)
{
	int i = 0;

	if (argument == NULL)
		return (0);

	while (argument[i] != '\0')
	{

		if (!isdigit(argument[i]) && argument[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
