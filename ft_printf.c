/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:55:31 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/17 18:22:44 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
// #include "./ft_putnbr_fd_mod.c"
// #include "./ft_putchar_fd.c"
// #include "./ft_putstr_fd.c"
// #include "./ft_strlen.c"
#include "./libft/libft.h"
#include "ft_printf.h"



int ft_printf(const char *str, ...)
{
	int				i;
	char			*s;
	long long		d;
	char			c;
	int				countchar[1];
	unsigned int	ud;

	countchar[0] = 0;
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
					countchar[0]++;
					// printf("\n%d\n", countchar[0]);
					write(1, &c, 1);
					continue ;
				case 's':
					s = va_arg(ap, char *);
					if (s == NULL)
						s = "(null)";
					countchar[0] += ft_strlen(s);
					// printf("\n%d\n", countchar[0]);
					ft_putstr_fd(s, 1);
					continue ;
				case 'p':
					d = (unsigned long long)va_arg(ap, unsigned long long);
					if (d == 0)
					{
						write(1, "(nil)", 5);
						countchar[0] += 5;
						continue ;
					}
					write(1, "0x", 2);
					countchar[0] += 2;
					printconvfromdec(16, d, "0123456789abcdef", countchar);
					// printf("\n%d\n", countchar[0]);
					continue ;
				case 'd':
					d = va_arg(ap, int);
					ft_putnbr_fd_mod(d, 1, countchar);
					// printf("\n%d\n", countchar[0]);
					continue ;
				case 'i':
					d = va_arg(ap, int);
					ft_putnbr_fd_mod(d, 1, countchar);
					// printf("\n%d\n", countchar[0]);
					continue ;
				case 'u':
					ud = (unsigned int) va_arg(ap, int);
					// printf("%lld", d);
					uIntPutnbr(ud, 1, countchar);
					// printf("\n%d\n", countchar[0]);
					continue ;
				case 'x':
					d = va_arg(ap, long long);
					if (d < 0)
						d += 4294967296;
					convertX(16, d, "0123456789abcdef", countchar);
					// printf("\n%d\n", countchar[0]);
					continue ;
				case 'X':
					d = va_arg(ap, long long);
					if (d < 0)
						d += 4294967296;
					convertX(16, d, "0123456789ABCDEF", countchar);
					// printf("\n%d\n", countchar[0]);
					continue ;
				case '%':
					ft_putchar_fd('%', 1);
					countchar[0]++;
					// printf("\n%d\n", countchar[0]);
					continue ;
			}
		}
		write(1, &str[i], 1);
		countchar[0]++;
	}
	va_end(ap);
	return countchar[0];
}

// int main()
// {
//     // char *s = "hello World!";
// 	// int count = 0;

//     // // printf("number: %lld, address: %p\n", i, &s);
//     // count = ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n\n", 'c', s, s, -12345, -54321, 15243, 5, -2);
// 	// 	printf("%d\n\n", count);

//     // count = printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n\n", 'c', s, s, -12345, -54321, 15243, 5, -2);
// 	printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	ft_printf(" %x %x %x %x %x %x %x\n\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

// ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

// 	// printf("%s NULL NULL\n\n", NULL);
//     // printconvfromdec(16, 110, "0123456789abcdef", &);
//     return 0;
// }
