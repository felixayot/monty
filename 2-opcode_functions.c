#include "monty.h"
/**
 * op_add - Function prototype
 * Description: Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 * Return: void
 */
void op_add(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tokens_error(short_stack_error(line_number, "add"));
return;
}

(*stack)->next->next->n += (*stack)->next->n;
op_pop(stack, line_number);
}

/**
* op_sub - Function prototype
* Description: Subtracts the second value from the top
* of a stack_t linked list by the top value.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
* Return: void
*/
void op_sub(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tokens_error(short_stack_error(line_number, "sub"));
return;
}

(*stack)->next->next->n -= (*stack)->next->n;
op_pop(stack, line_number);
}

/**
* op_div - Function prototype
* Description: Divides the second value from the top
* of a stack_t linked list by the top value.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
* Return: void
*/
void op_div(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tokens_error(short_stack_error(line_number, "div"));
return;
}

if ((*stack)->next->n == 0)
{
set_opcode_tokens_error(div_error(line_number));
return;
}

(*stack)->next->next->n /= (*stack)->next->n;
op_pop(stack, line_number);
}

/**
* op_mul - Function prototype
* Description: Multiplies the second value from the top of
* a stack_t linked list by the top value.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
* Return: void
*/
void op_mul(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tokens_error(short_stack_error(line_number, "mul"));
return;
}

(*stack)->next->next->n *= (*stack)->next->n;
op_pop(stack, line_number);
}

/**
* op_mod - Function prototype
* Description: Computes the modulus of the second value from the
* top of a stack_t linked list  by the top value.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @line_number: The current working line number of a Monty bytecodes file.
* Return: void
*/
void op_mod(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_opcode_tokens_error(short_stack_error(line_number, "mod"));
return;
}

if ((*stack)->next->n == 0)
{
set_opcode_tokens_error(div_error(line_number));
return;
}

(*stack)->next->next->n %= (*stack)->next->n;
op_pop(stack, line_number);
}
