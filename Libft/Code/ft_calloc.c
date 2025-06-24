/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:21:00 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 21:57:05 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t			index;
	unsigned char	*p;

	p = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		p[index] = '\0';
		index++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*c_ptr;
	size_t	prod;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	prod = nmemb * size;
	if (prod != 0 && nmemb != (prod / size))
		return (NULL);
	else
	{
		c_ptr = malloc(nmemb * size);
		if (!c_ptr)
			return (NULL);
		ft_bzero(c_ptr, prod);
		return (c_ptr);
	}
}
