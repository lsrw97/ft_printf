/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:40:57 by eelisaro          #+#    #+#             */
/*   Updated: 2022/11/29 20:18:22 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned long	i;
	size_t			x;

	if (nmemb == 0 || size == 0)
		return (NULL);
	x = nmemb * size;
	if (nmemb != x / size)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < x)
		*((char *)ptr + i++) = 0;
	return (ptr);
}
