#include "monty.h"
/**
 * set_opcode_tokens_error - Function prototype
 * Description: Sets last element of opcode_tokens to be an error code.
 * @error_code: Integer to store as a string in opcode_tokens.
 * Return: void
 */
void set_opcode_tokens_error(int error_code)
{
int toks_len = 0, i = 0;
char *exit_str = NULL;
char **new_toks = NULL;

toks_len = token_arr_len();
new_toks = malloc(sizeof(char *) * (toks_len + 2));
if (!opcode_tokens)
{
malloc_error();
return;
}
while (i < toks_len)
{
new_toks[i] = opcode_tokens[i];
i++;
}
exit_str = get_int(error_code);
if (!exit_str)
{
free(new_toks);
malloc_error();
return;
}
new_toks[i++] = exit_str;
new_toks[i] = NULL;
free(opcode_tokens);
opcode_tokens = new_toks;
}