/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:26:45 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 21:58:02 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	getlen(char const *s)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

static void	create_sub(char const *s, char *new, size_t len)
{
	size_t	ind;

	ind = 0;
	while (ind < len)
	{
		new[ind] = s[ind];
		ind++;
	}
	new[ind] = '\0';
}

static char	*start_at_end(void)
{
	char	*no_str;

	no_str = (char *)malloc(1 * sizeof(char));
	if (!no_str)
		return (NULL);
	no_str[0] = '\0';
	return (no_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	to_alloc;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = getlen(s);
	if (start >= s_len)
		return (start_at_end());
	if ((start + len) > s_len)
		to_alloc = s_len - start;
	else
		to_alloc = len;
	new = (char *)malloc((to_alloc + 1) * sizeof(char));
	if (!new)
		return (NULL);
	create_sub(s + start, new, to_alloc);
	return (new);
}
