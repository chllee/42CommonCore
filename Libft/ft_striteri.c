/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:42:49 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:08:15 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_len(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	ind;
	unsigned int	len;

	ind = 0;
	len = get_len(s);
	while (ind < len)
	{
		f(ind, s);
		s++;
		ind++;
	}
}
