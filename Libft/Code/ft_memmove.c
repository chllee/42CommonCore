/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:51:56 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:03:38 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void	*normalmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			val;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	val = 0;
	while (val < n)
	{
		d[val] = s[val];
		val++;
	}
	return (dest);
}

static void	*rvsmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src || n == 0)
		return (dest);
	if ((unsigned char *)dest < (unsigned char *)src)
		return (normalmove(dest, src, n));
	else
		return (rvsmove(dest, src, n));
}
