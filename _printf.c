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
			print_char += _putchar(*format);
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
				case 'i':
				case 'd':
					print_number(va_arg(args, int));
					break;
				default:
					print_char += _putchar('%');
					print_char += _putchar(*format);
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (print_char);
}
