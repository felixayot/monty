#include "monty.h"
/**
 * get_int - Function prototype
 * Description: gets a character pointer to new string containing int
 * @num: number to convert to string
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(int num)
{
unsigned int temp;
int length = 0;
long num_l = 0;
char *ret;

temp = _abs(num);
length = get_numbase_len(temp, 10);

if (num < 0 || num_l < 0)
length++;
ret = malloc(length + 1);
if (!ret)
return (NULL);

fill_numbase_buff(temp, 10, ret, length);
if (num < 0 || num_l < 0)
ret[0] = '-';

return (ret);
}

/**
* _abs - Function prototype
* Description: gets the absolute value of an integer
* @i: integer to get absolute value of
* Return: unsigned integer abs rep of i
*/
unsigned int _abs(int i)
{
if (i < 0)
return (-(unsigned int)i);
return ((unsigned int)i);
}

/**
* get_numbase_len - Function prototype
* Description: gets length of buffer needed for an unsigned int
* @num: number to get length needed for
* @base: base of number representation used by buffer
* Return: integer containing length of buffer needed
*/
int get_numbase_len(unsigned int num, unsigned int base)
{
int len = 1;

while (num > base - 1)
{
len++;
num /= base;
}
return (len);
}

/**
* fill_numbase_buff - Function prototype
* Description: fills buffer with correct numbers up to base 36
* @num: number to convert to string given base
* @base: base of number used in conversion, only works up to base 36
* @buff: buffer to fill with result of conversion
* @buff_size: size of buffer in bytes
* Return: void.
*/
void fill_numbase_buff(unsigned int num, unsigned int base,
char *buff, int buff_size)
{
int rem, i = buff_size - 1;

buff[buff_size] = '\0';
while (i >= 0)
{
rem = num % base;
if (rem > 9)
buff[i] = rem + 87;
else
buff[i] = rem + '0';
num /= base;
i--;
}
}
