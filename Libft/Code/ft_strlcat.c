/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:00 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:09:08 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include "libft.h"

static void	copy(char *dst, const char *src, size_t size, size_t d_len)
{
	size_t	s_ind;
	size_t	to_cat;

	to_cat = size - d_len - 1;
	s_ind = 0;
	while (src[s_ind] && s_ind < to_cat)
	{
		dst[d_len] = src[s_ind];
		s_ind++;
		d_len++;
	}
	dst[d_len] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	if (size <= d_len)
		return (s_len + size);
	copy(dst, src, size, d_len);
	return (d_len + s_len);
}
