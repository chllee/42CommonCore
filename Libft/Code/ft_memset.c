/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:13:47 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:04:32 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	chr;
	unsigned char	*ptr;

	if ((char)c > 256)
		c = (c % 256);
	chr = (unsigned char)c;
	ptr = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		ptr[index] = chr;
		index++;
	}
	return (ptr);
}
