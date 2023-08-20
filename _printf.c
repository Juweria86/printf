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
 * _putchar - writes the character c to stdout
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
				case 'c':
					print_char += _putchar(va_arg(args, int));
					break;
				case 's':
					print_char += print_string(va_arg(args, char *));
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
