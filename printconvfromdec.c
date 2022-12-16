#include "ft_printf.h"
#include <stdint.h>

void	printconvfromdec(int tobase, uintptr_t number, char *set, int *len)
{
	if (number / tobase == 0)
	{
		write(1, &set[number % tobase], 1);
		len[0]++;
	}
	else
	{
		printconvfromdec(tobase, (number / tobase), set, len);
		if (number == 0)
			number *= -1;
		write(1, &set[number % tobase], 1);
		len[0]++;
	}
}
