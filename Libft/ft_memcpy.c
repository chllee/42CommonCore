/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:07:28 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:03:10 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s_ptr;
	unsigned char	*d_ptr;
	size_t			index;

	s_ptr = (unsigned char *)src;
	d_ptr = (unsigned char *)dest;
	index = 0;
	while (index < n)
	{
		d_ptr[index] = s_ptr[index];
		index++;
	}
	return (d_ptr);
}
