#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Current line number in the bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	stack_t *top = *stack;
	*stack = top->next;
	free(top);
}
<<<<<<< HEAD

=======
>>>>>>> 8162b8cad5aaee578cd608215011dcd28cbfead0
