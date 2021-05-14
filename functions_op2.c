#include "monty.h"

/**
 * op_swap - function that swaps the first 2 nodes in a linked list
 * @stack: a pointer to the head of a linked list
 * @l: the line number
 *
 * Return: nothing
 */

void op_swap(stack_t **stack, unsigned int l)
{
	stack_t *current = *stack;
	stack_t *second_node;
	int temp;

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", l);
		free_buff();
		exit(EXIT_FAILURE);
	}

	if (current && current->next)
	{
		second_node = current->next;
		temp = current->n;
		current->n = second_node->n;
		second_node->n = temp;
	}

	else
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", l);
		free_buff();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_nop - function that does nothing when executed
 * @stack: a pointer to the head of the linked list
 * @line_number: the line number
 * Return: nothing
 */

void op_nop(stack_t **stack, unsigned int number)
{
	(void)stack;
	(void)number;
}

/**
 * op_sub - subtracts the first two nodes together
 * @stack: a pointer to the head of a linked list
 * @number: the line number
 * Return: nothing
 */

void op_sub(stack_t **stack, unsigned int number)
{
	stack_t *current = *stack;
	stack_t *new_node;

	if (!current || !current->next)
		sub_error(number);

	new_node = current->next;
	new_node->n = new_node->n - current->n;
	op_pop(stack, number);
}

/**
 * op_div - divides the first two nodes together
 * @stack: a pointer to the head of a linked list
 * @number: the line number
 * Return: nothing
 */

void op_div(stack_t **stack, unsigned int number)
{
	stack_t *current = *stack;
	stack_t *new_node;

	if (!current || !current->next)
		div_error(number);

	if (current->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", number);
		exit(EXIT_FAILURE);
	}
	new_node= current->next;
	new_node->n = new_node->n / current->n;
	op_pop(stack, number);
}

/**
 * op_mul - multiplies the first two nodes together
 * @stack: a pointer to the head of a linked list
 * @number: the line number
 * Return: nothing
 */
void op_mul(stack_t **stack, unsigned int number)
{
	stack_t *current = *stack;
	stack_t *second_node;

	if (!current || !current->next)
		mul_error(number);

	second_node = current->next;
	second_node->n = second_node->n * current->n;
	op_pop(stack, number);
}
