#include "monty.h"

/**
 * pall - Prints all values on the stack
 * @stack: Pointer to the top of the stack
 */
void pall(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
