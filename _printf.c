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
 *
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
	return (write(1, s,  _strlen(s)));
}
/**
 * print_number -prints integers.
 * @n: an integer
 * Return: i
 */
int print_number(int n)
{
	unsigned int i;

	i = n;

	if (n < 0)
	{
		_putchar('-');
		i = -i;
	}
	if (i / 10)
	{
		print_number(i / 10);
	}
	_putchar(i % 10 + '0');
	return (i);
}
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of chracters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int print_char = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			print_char += _putchar(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			switch (*format)
			{

				case '%':
					print_char += _putchar('%');
					break;
				case 'd':
				case 'i':
					print_char += print_number(va_arg(args, int));
					break;
				case 'c':
					print_char += _putchar(va_arg(args, int));
					break;
				case 's':

					print_char += print_string(va_arg(args, char *));
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (print_char);
}
