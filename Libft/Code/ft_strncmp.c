/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:08:21 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:11:07 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	int				rtn_val;
	unsigned char	v1;
	unsigned char	v2;

	index = 0;
	while (index < n)
	{
		if (s1[index] == '\0' && s2[index] == '\0')
			return (0);
		if (s1[index] != s2[index])
		{
			v1 = (unsigned char)s1[index];
			v2 = (unsigned char)s2[index];
			rtn_val = v1 - v2;
			return (rtn_val);
		}
		else
			index++;
	}
	return (0);
}
