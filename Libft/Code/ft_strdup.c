/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:59:30 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:07:59 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int	get_len(const char *s)
{
	int	s_len;

	s_len = 0;
	while (*s != '\0')
	{
		s_len++;
		s++;
	}
	return (s_len);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		index;
	int		s_len;

	index = 0;
	s_len = get_len(s);
	new = (char *)malloc((s_len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (index < s_len)
	{
		new[index] = s[index];
		index++;
	}
	new[s_len] = '\0';
	return (new);
}
