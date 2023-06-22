#include "monty.h"
/**
 * op_push - Function prototype
 * Description: Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *new;
int i;

new = malloc(sizeof(stack_t));
if (new == NULL)
{
set_opcode_tokens_error(malloc_error());
return;
}

if (opcode_tokens[1] == NULL)
{
set_opcode_tokens_error(no_int_error(line_number));
return;
}

for (i = 0; opcode_tokens[1][i]; i++)
{
if (opcode_tokens[1][i] == '-' && i == 0)
continue;
if (opcode_tokens[1][i] < '0' || opcode_tokens[1][i] > '9')
{
set_opcode_tokens_error(no_int_error(line_number));
return;
}
}
new->n = atoi(opcode_tokens[1]);

if (check_mode(*stack) == STACK)
{
tmp = (*stack)->next;
new->prev = *stack;
new->next = tmp;
if (tmp)
tmp->prev = new;
(*stack)->next = new;
}
else
{
tmp = *stack;
while (tmp->next)
tmp = tmp->next;
new->prev = tmp;
new->next = NULL;
tmp->next = new;
}
}

/**
* op_pall - Function prototype
* Description: Prints the values of a stack_t linked list.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
* Return: void
*/
void op_pall(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = (*stack)->next;

while (tmp)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
(void)line_number;
}

/**
* op_pint - Function prototype
* Description: Prints the top value of a stack_t linked list.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
* Return: void
*/
void op_pint(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL)
{
set_opcode_tokens_error(pint_error(line_number));
return;
}

printf("%d\n", (*stack)->next->n);
}


/**
* op_pop - Function prototype
* Description: Removes the top value element of a stack_t linked list.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
* Return: void
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
stack_t *next = NULL;

if ((*stack)->next == NULL)
{
set_opcode_tokens_error(pop_error(line_number));
return;
}

next = (*stack)->next->next;
free((*stack)->next);
if (next)
next->prev = *stack;
(*stack)->next = next;
}

/**
* op_swap - Function prototype
* Description: Swaps the top two value elements of a stack_t linked list.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
* Return: void
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tokens_error(short_stack_error(line_number, "swap"));
return;
}

tmp = (*stack)->next->next;
(*stack)->next->next = tmp->next;
(*stack)->next->prev = tmp;
if (tmp->next)
tmp->next->prev = (*stack)->next;
tmp->next = (*stack)->next;
tmp->prev = *stack;
(*stack)->next = tmp;
}
