#include "main.h"
/**
 * print_binary - prints binary of unsigned int
 * @b: an integer to be converted to binary
 */
void print_binary(unsigned int b)
{
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
	int leading_zeros = 1;
	
	if (b == 0)
	{
		_putchar('0');
		return;
	}
	while (mask != 0)
	{
		if ((b & mask) != 0)
		{
			leading_zeros = 0;
			_putchar('1');
		}
		else if (!leading_zeros)
			_putchar('0');
		mask >>= 1;
	}
}
