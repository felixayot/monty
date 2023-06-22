#define _GNU_SOURCE
#include "monty.h"
/**
 * free_tokens - Function prototype
 * Description: Frees the global variable opcode_tokens array of strings.
 * Return: void
 */
void free_tokens(void)
{
size_t i = 0;

if (opcode_tokens == NULL)
return;

for (i = 0; opcode_tokens[i]; i++)
free(opcode_tokens[i]);

free(opcode_tokens);
}

/**
* token_arr_len - Function prototype
* Description: Gets the length of current op_toks.
* Return: Length of current opcode_tokens.
*/
unsigned int token_arr_len(void)
{
unsigned int toks_len = 0;

while (opcode_tokens[toks_len])
toks_len++;
return (toks_len);
}

/**
* is_empty_line - Function prototype
* Description: Checks if a line read from getline only contains delimiters.
* @line: A pointer to the line.
* @delims: A string of delimiter characters.
* Return: 1 if the line only contains delimiters, Otherwise 0.
*/
int is_empty_line(char *line, char *delims)
{
int i, j;

for (i = 0; line[i]; i++)
{
for (j = 0; delims[j]; j++)
{
if (line[i] == delims[j])
break;
}
if (delims[j] == '\0')
return (0);
}

return (1);
}

/**
* get_opcode_function - Function prototype
* Description: Matches an opcode with its corresponding function.
* @opcode: The opcode to match.
*
* Return: A pointer to the corresponding function.
*/
void (*get_opcode_function(char *opcode))(stack_t**, unsigned int)
{
instruction_t op_funcs[] = {
{"push", op_push},
{"pall", op_pall},
{"pint", op_pint},
{"pop", op_pop},
{"swap", op_swap},
{"add", op_add},
{"nop", op_nop},
{"sub", op_sub},
{"div", op_div},
{"mul", op_mul},
{"mod", op_mod},
{"pchar", op_pchar},
{"pstr", op_pstr},
{"rotl", op_rotl},
{"rotr", op_rotr},
{"stack", op_stack},
{"queue", op_queue},
{NULL, NULL}
};
int i;

for (i = 0; op_funcs[i].opcode; i++)
{
if (strcmp(opcode, op_funcs[i].opcode) == 0)
return (op_funcs[i].f);
}

return (NULL);
}

/**
* monty_prog - Function prototype
* Description: Primary function to execute a Monty bytecodes script.
* @script_fd: File descriptor for an open Monty bytecodes script.
* Return: EXIT_SUCCESS (Success), corresponding error code on failure.
*/
int monty_prog(FILE *script_fd)
{
stack_t *stack = NULL;
char *line = NULL;
size_t len = 0, exit_status = EXIT_SUCCESS;
unsigned int line_number = 0, prev_tok_len = 0;
void (*op_func)(stack_t**, unsigned int);

if (init_stack(&stack) == EXIT_FAILURE)
return (EXIT_FAILURE);

while (getline(&line, &len, script_fd) != -1)
{
line_number++;
opcode_tokens = strtow(line, DELIMS);
if (opcode_tokens == NULL)
{
if (is_empty_line(line, DELIMS))
continue;
free_stack(&stack);
return (malloc_error());
}
else if (opcode_tokens[0][0] == '#')
{
free_tokens();
continue;
}
op_func = get_opcode_function(opcode_tokens[0]);
if (op_func == NULL)
{
free_stack(&stack);
exit_status = unknown_op_error(opcode_tokens[0], line_number);
free_tokens();
break;
}
prev_tok_len = token_arr_len();
op_func(&stack, line_number);
if (token_arr_len() != prev_tok_len)
{
if (opcode_tokens && opcode_tokens[prev_tok_len])
exit_status = atoi(opcode_tokens[prev_tok_len]);
else
exit_status = EXIT_FAILURE;
free_tokens();
break;
}
free_tokens();
}
free_stack(&stack);

if (line && *line == 0)
{
free(line);
return (malloc_error());
}

free(line);
return (exit_status);
}
