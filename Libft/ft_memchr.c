/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:25:43 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:02:30 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new;
	size_t			index;

	new = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (new[index] == (unsigned char)c)
			return (new + index);
		else
			index++;
	}
	return (NULL);
}
