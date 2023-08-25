#include "main.h"
/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_index;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_index = *i + 1; format[curr_index] != '\0'; curr_index++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_index] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_index - 1;

	return (flags);
}

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @args: list of arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list args)
{
	int current_index = *i + 1;
	int precision = -1;

	if (format[current_index] != '.')
		return (precision);

	precision = 0;

	for (current_index += 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			precision *= 10;
			precision += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = current_index - 1;

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
 * @args: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list args)
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
