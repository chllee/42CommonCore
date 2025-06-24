/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:36:55 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 21:57:52 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*emptystr(void)
{
	char	*rtn;

	rtn = (char *)malloc(1 * sizeof(char));
	rtn[0] = '\0';
	return (rtn);
}

static int	is_match(char c, char const *set)
{
	int	ind;

	ind = 0;
	while (set[ind] != '\0')
	{
		if (c == set[ind])
			return (1);
		ind++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rtn;
	size_t	start;
	size_t	end;
	size_t	len;

	if (ft_strlen(s1) == 0)
		return (emptystr());
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && is_match(s1[start], set) == 1)
		start++;
	while (end >= 0 && is_match(s1[end - 1], set) == 1)
		end--;
	if (start == ft_strlen(s1) || end == 0)
		return (emptystr());
	len = end - start;
	rtn = ft_substr(s1, start, len);
	return (rtn);
}
