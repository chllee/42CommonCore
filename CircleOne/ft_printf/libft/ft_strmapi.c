/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:15:54 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:10:11 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_len(char const *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		ind;
	int		len;
	char	*n_arr;

	ind = 0;
	len = get_len(s);
	n_arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!n_arr)
		return (NULL);
	while (ind < len)
	{
		n_arr[ind] = f(ind, s[ind]);
		ind++;
	}
	n_arr[len] = '\0';
	return (n_arr);
}
