#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_number -prints integers.
 * @n: an integer
 */
void print_number(int n)
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
				case 'd':
					print_number(va_arg(args, int));
					print_char++;
					break;
				case 'i':
					print_number(va_arg(args, int));
					print_char++;
					break;
				default:
					print_char += _putchar('%');
					print_char += _putchar(*format);
			}
		}
		format++;
	}
	va_end(args);
	return (print_char);
}


