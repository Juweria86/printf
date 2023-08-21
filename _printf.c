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
	char buffer[BUFF_SIZE];
	int buff_index = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			buffer[buff_index] = _putchar(*format);

		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			switch (*format)
			{

				case '%':
					 _putchar('%');
					break;
				case 'c':
					_putchar(va_arg(args, int));
					break;
				case 'i':
				case 'd':
					print_number(va_arg(args, int));
					break;
				case 's':

					print_string(va_arg(args, char *));
					break;
				default:
					buff_index= _putchar(*format);
					break;
			}
			
		}
		format++;
	}
	va_end(args);
	return (print_char);
}
