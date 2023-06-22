#include "monty.h"
/**
 * op_rotl - Function prototype
 * Description: Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 * Return: void
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
stack_t *top, *bottom;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
return;

top = (*stack)->next;
bottom = (*stack)->next;
while (bottom->next != NULL)
bottom = bottom->next;

top->next->prev = *stack;
(*stack)->next = top->next;
bottom->next = top;
top->next = NULL;
top->prev = bottom;

(void)line_number;
}

/**
* op_rotr - Function prototype
* Description: Rotates the bottom value of a stack_t linked list to the top.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
* Return: void
*/
void op_rotr(stack_t **stack, unsigned int line_number)
{
stack_t *top, *bottom;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
return;

top = (*stack)->next;
bottom = (*stack)->next;
while (bottom->next != NULL)
bottom = bottom->next;

bottom->prev->next = NULL;
(*stack)->next = bottom;
bottom->prev = *stack;
bottom->next = top;
top->prev = bottom;

(void)line_number;
}

/**
* op_stack - Function prototype
* Description: Converts a queue to a stack.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
* Return: void
*/
void op_stack(stack_t **stack, unsigned int line_number)
{
(*stack)->n = STACK;
(void)line_number;
}

/**
* op_queue - Function prototype
* Description: Converts a stack to a queue.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
* Return: void
*/
void op_queue(stack_t **stack, unsigned int line_number)
{
(*stack)->n = QUEUE;
(void)line_number;
}