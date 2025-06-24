/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:41:01 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:11:42 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = 0;
	if (s == NULL)
		return (NULL);
	if ((char)c == 0 && *s == '\0')
		return ((char *)s);
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			tmp = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	if (tmp == 0)
		return (NULL);
	return (tmp);
}
