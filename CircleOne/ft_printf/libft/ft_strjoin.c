/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:47:19 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:08:33 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_len(char const *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		t_len;
	int		index_1;
	int		index_2;
	char	*new;

	t_len = get_len(s1) + get_len(s2);
	new = (char *)malloc((t_len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	index_1 = 0;
	while (s1[index_1] != '\0')
	{
		new[index_1] = s1[index_1];
		index_1++;
	}
	index_2 = 0;
	while (s2[index_2] != '\0')
	{
		new[index_1] = s2[index_2];
		index_1++;
		index_2++;
	}
	new[index_1] = '\0';
	return (new);
}
