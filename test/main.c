#include <stdio.h>
#include <stdarg.h>

void printValues(char *types, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, types);
	while (types[i] != '\0')
	{
		switch (types[i])
		{
		case 'i':
			printf("%d ", va_arg(ap,int));
			break ;
		case 'd':
			printf("%f ", va_arg(ap, double));
			break;
		case 'c':
			printf("%c ", (char)va_arg(ap, int));
			break;
		case 's':
			printf("%s ", va_arg(ap, char *));
			break;
		default:
			break;
		}
		i++;
	}
	va_end(ap);

	printf("\n");
}

int main()
{
	printValues("i", 10);
	printValues("ci", 'a', 10);
	printValues("dci", 1.2987897, 'a', 10);
	printValues("sicd", "helloword", 10, 'a', 1.1234125);

	return (0);
}