#include "main.h"
/**
 * _strlen -function that returns the length of a string.
 * @s: character
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
/**
 *  _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));

}
/**
 * print_string  - prints string
 * @s: string to be printed
 * Return: prints length of string
 */
int print_string(char *s)
{
	if (s == NULL)
		s = "(null)";
	return (write(1, s, _strlen(s)));
}
/**
 * print_number -function that prints an integer
 * @n: an integer
 */
int print_number(int n)
{
	int tmp_n = n;
	int n1 = 0;
	int index, i = 0;
	char digits[12];


	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	if (n < 0)
	{
		_putchar('-');
		tmp_n = -n;
	}
	while (tmp_n != 0)
	{
		tmp_n /= 10;
		n1++;
	}
	index = n1 - 1;
	tmp_n = n < 0 ? -n : n;
	while (tmp_n != 0)
	{
		digits[index] = tmp_n % 10 + '0';
		tmp_n /= 10;
		index--;
	}
	while (i < n1)
	{
		_putchar(digits[i]);
		i++;
	}
	return (n1);
}
