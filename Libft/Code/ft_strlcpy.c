/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:35:08 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:09:35 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>

static size_t	getlen(const char *src)
{
	size_t	ind;

	ind = 0;
	while (src[ind] != '\0')
		ind++;
	return (ind);
}

static void	copystr(char *dst, const char *src, size_t size)
{
	size_t	ind;

	ind = 0;
	while (ind < size && src[ind] != '\0')
	{
		dst[ind] = src[ind];
		ind++;
	}
	dst[ind] = '\0';
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = getlen(src);
	if (size > 0)
		copystr(dst, src, (size - 1));
	return (len);
}
