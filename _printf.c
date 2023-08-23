#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of chracters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int char_print = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			char_print += _putchar(*format);
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			switch (*format)
			{
				case '%':
					char_print+= _putchar('%');
					break;
				case 'c':
					char_print += _putchar(va_arg(args, int));
					break;
				case 's':
<<<<<<< HEAD
					print_char += print_string(va_arg(args, char *));
=======
					char_print += print_string(va_arg(args, char *));
>>>>>>> origin/main
					break;
				default:
					char_print += _putchar('%');
					char_print += _putchar(*format);
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (print_char);
}
