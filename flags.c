#include "main.h"
/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int currentIndex = *i + 1;
	int flags = 0, j;
	const char flagCharacters[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flagValues[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	while (format[currentIndex] != '\0')
	{
		for (j = 0; flagCharacters[j] != '\0'; j++)
		{
			if (format[currentIndex] == flagCharacters[j])
			{
				flags |= flagValues[j];
				break;
			}
		}
		if (flagCharacters[j] == 0)
			return (flags);
		currentIndex++;
	}
	*i = currentIndex - 1;
	return (flags);
}
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int currentIndex = *i + 1;
	int precision = -1;

	if (format[currentIndex] != '.')
		return (precision);

	precision = 0;
	while (format[currentIndex] != '\0')
	{
		if (is_digit(format[currentIndex]))
		{
			precision *= 10;
			precision += format[currentIndex] - '0';
		}
		else if (format[currentIndex] == '*')
		{
			currentIndex++;
			precision = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
		currentIndex++;
	}
	*i = currentIndex - 1;
	return (precision);
}
/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
        int currentIndex = *i + 1;
        int size = 0;

        if (format[currentIndex] == 'l')
                size = S_LONG;
        else if (format[currentIndex] == 'h')
                size = S_SHORT;
        *i = (size != 0) ? currentIndex : currentIndex - 1;
        return (size);
}
/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
        int currentIndex = *i + 1;
        int width = 0;

        while (format[currentIndex] != '\0')
        {
                if (is_digit(format[currentIndex]))
                {
                        width *= 10;
                        width += format[currentIndex] - '0';
                }
                else if (format[currentIndex] == '*')
                {
                        currentIndex++;
                        width = va_arg(list, int);
                        break;
                }
                else
                {
                        break;
                }
                currentIndex++;
        }
        *i = currentIndex - 1;
        return (width);
}
