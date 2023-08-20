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
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of chracters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int print_char = 0;
	char value, *s;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			print_char += write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			switch (*format)
			{
				case '%':
					print_char += write(1, format, 1);
					break;
				case 'c':
					value = va_arg(args, int);
					print_char += write(1, &value, 1);
					break;
				case 's':
					s = va_arg(args, char *);
					print_char += write(1, s, _strlen(s));
					break;
				default:
					va_end(args);
					return (-1);
			}
		}
		format++;
	}
	va_end(args);
	return (print_char);
}
