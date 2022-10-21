#include "main.h"

/**
 * _printf - function that acts exactly like the in-built printf function
 * @format: arguments passed to the function, remains constant
 * Return: the output of passed arguments
 */
int _printf(const char *format, ...)
{
	va_list(printfarg);
	char *str, *ptr;
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
				case 'c':
					buffer[j] = (char)va_arg(printfarg, int);
					j++;
					break;
				case 's':
					str = va_arg(printfarg, char *);
					ptr = &buffer[j];
					strcpy(ptr, str);
					j += strlen(str);
					break;
				case '%':
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
	fwrite(buffer, j, 1, stdout);
	va_end(printfarg);
	return (j);
}
