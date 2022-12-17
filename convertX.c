#include "ft_printf.h"

void	convertX(int tobase, unsigned int number, char *set, int *len)
{
	if (number / tobase == 0)
	{
		write(1, &set[number % tobase], 1);
		len[0]++;
	}
	else
	{
		convertX(tobase, (number / tobase), set, len);
		if (number == 0)
			number *= -1;
		write(1, &set[number % tobase], 1);
		len[0]++;
	}
}
