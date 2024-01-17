#define _POSIX_C_SOURCE 200809L

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

interpreter_t interpreter = {NULL, NULL, NULL, 0};
/**
* monty_interpreter - Entry point for the Monty code interpreter
* @argument_count: number of command line arguments
* @argument_values: Monty file location
* Return: 0 on success
*/
int monty_interpreter(int argument_count, char *argument_values[])
{
	char *file_content;
	FILE *file_pointer;
	size_t buffer_size = 0;
	size_t read_line = 1;
	stack_t *data_stack = NULL;
	unsigned int line_counter = 0;

	if (argument_count != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argument_values[0]);
		exit(EXIT_FAILURE);
	}
	file_pointer = fopen(argument_values[1], "r");
	interpreter.file = file_pointer;
	if (!file_pointer)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argument_values[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		file_content = NULL;
		read_line = getline(&file_content, &buffer_size, file_pointer);
		interpreter.content = file_content;
		line_counter++;
		if (read_line > 0)
		{
			execute(file_content, &data_stack, line_counter, file_pointer);
		}
		free(file_content);
	}
	free_stack(data_stack);
	fclose(file_pointer);
	return (0);
}
