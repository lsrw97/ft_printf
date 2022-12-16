#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./ft_putnbr_fd.c"
#include "./ft_putchar_fd.c"
#include "./ft_putstr_fd.c"


void	printconvfromdec(int tobase, long long number)
{
	char	*set;

	set = "0123456789abcdef";
	if (number / tobase == 0)
	{
		if (number < 0)
		{
			write(0, "-", 1);
			number *= -1;
		}
		write(0, &set[number % tobase], 1);
	}
	else
	{
		printconvfromdec(tobase, (number / tobase));
		if (number < 0)
			number *= -1;
		write(0, &set[number % tobase], 1);
	}
}

int	ft_printf(char *str, ...)
{
	int				i;
	char			*s;
	long long		d;
	char			c;
	int				countchar;
	unsigned int	ud;

	countchar = 0;
	printf("%s\n", str);

	va_list ap;

	va_start(ap, str);

	i = -1;

	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			switch (str[i])
			{
				case 'c':
					c = va_arg(ap, int);
					write(0, &c, 1);
					continue ;
				case 's':
					s = va_arg(ap, char *);
					ft_putstr_fd(s, 0);
					continue ;
				case 'p':
					d = va_arg(ap, long long);
					write(0, "0x10", 4);
					printconvfromdec(16, d);
					continue ;
				case 'd':
					d = va_arg(ap, int);
					ft_putnbr_fd(d, 0);
					continue ;
				case 'i':
					d = va_arg(ap, int);
					ft_putnbr_fd(d, 0);
					continue ;
				case 'u':
					ud = va_arg(ap, unsigned int);
					ft_putnbr_fd(ud, 0);
					continue ;
				case 'x':
					d = va_arg(ap, long long);
					printconvfromdec(16, d);
					continue ;
				case 'X':
					d = va_arg(ap, long long);
					printconvfromdec(16, d);
					continue ;
				case '%':
					ft_putchar_fd('%', 0);
					continue ;
			}
		}
		write(0, &str[i], 1);
	}
	va_end(ap);
	return countchar;
}

int main()
{
    char *s = "hello World!";
    // printf("number: %lld, address: %p\n", i, &s);
    ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n\n", 'c', s, s, -12345, -54321, 15243, 92938, -4829);
    printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n\n", 'c', s, s, -12345, -54321, 15243, -92938, -4829);

    printconvfromdec(16, 110);
    return 0;
}
