#define _GNU_SOURCE
#include "monty.h"
#include <sys/types.h>
#include <stdio.h>

interpreter_t interpreter = {NULL, NULL, NULL, 0};
/**
* main - Monty code interpreter entry point
* @argc: number of command line arguments
* @argv: array of command line arguments
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *file_content;
	FILE *file_pointer;
	size_t buffer_size = 0;
	int read_line = 1;
	stack_t *data_stack = NULL;
	unsigned int line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file_pointer = fopen(argv[1], "r");
	interpreter.file = file_pointer;
	if (!file_pointer)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
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
