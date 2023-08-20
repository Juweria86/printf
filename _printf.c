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
			write(1, format, 1);
			print_char++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case '%':
					write(1, format, 1);
					print_char++;
					break;
				case 'c':
					value = va_arg(args, int);
					write(1, &value, 1);
					print_char++;
					break;
				case 's':
					s = va_arg(args, char *);
					write(1, s, _strlen(s));
					print_char += _strlen(s);
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (print_char);
}
