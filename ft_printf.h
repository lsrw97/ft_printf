#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include "./libft/libft.h"
#include <stdint.h>


int ft_printf(const char *str, ...);
void	ft_putnbr_fd_mod(long n, int fd, int *len);
void	printconvfromdec(int tobase, uintptr_t number, char *set, int *len);
#endif
