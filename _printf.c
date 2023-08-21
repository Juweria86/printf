#include "main.h"
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
			if (*format == ' ')
				return (-1);
			if (*format == '%')
				print_char += _putchar('%');
			else if (*format == 'c')
				print_char += _putchar(va_arg(args, int));
			else if (*format == 's')
				print_char += print_string(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
			{
				print_number(va_arg(args, int));
				print_char++;
			}
		}
		format++;
	}
	va_end(args);
	return (print_char);
}
