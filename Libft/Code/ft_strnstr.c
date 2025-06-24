/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:10:16 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 21:50:50 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>

static size_t	checksub(const char *m, const char *s, size_t index, size_t len)
{
	size_t	s_ind;
	size_t	m_ind;

	s_ind = 0;
	m_ind = index;
	while (s[s_ind] != '\0')
	{
		if (m[m_ind] != s[s_ind] || (m_ind >= len))
			return (0);
		else
		{
			s_ind++;
			m_ind++;
		}
	}
	return (1);
}

char	*ft_strnstr(const char *main, const char *sub, size_t len)
{
	size_t	index;

	if (sub[0] == '\0')
		return ((char *)main);
	if (main[0] == '\0')
		return (NULL);
	index = 0;
	while (index < len && main[index] != '\0')
	{
		if (main[index] == sub[0])
		{
			if (checksub(main, sub, index, len) == 1)
				return ((char *)(main + index));
		}
		index++;
	}
	return (NULL);
}
