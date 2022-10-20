#include "main.h"

/**
 * _printf - function that acts exactly like the in-built printf function
 * @format: arguments passed to the function, remains constant
 * Return: the output of passed arguments
 */
int _printf(const char *format, ...)
{
	va_list(printfarg);
	char *str;
	char buffer[100] = {0};
	int i = 0, j = 0;

	va_start(printfarg, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
				case 'c' :
					buffer[j] = (char)va_arg(printfarg, int);
					j++;
					break;

				case 's' :
					str = va_arg(printfarg, char *);
					strcpy(buffer[j], str);
					j += strlen(str);
					break;

				case '%' :
					buffer[j] = format[i];
					j++;
					break;
			}
		}
		else
		{
			buffer[j] = format[i];
			j++;
		}
		i++;
	}
	write(1, &buffer, strlen(buffer));
	va_end(printfarg);
	return (j);
}
