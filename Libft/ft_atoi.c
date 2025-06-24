/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:42:05 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 21:57:25 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_num(const char *str, int index)
{
	int	final_num;
	int	r_ind;

	r_ind = index;
	final_num = 0;
	if (str[r_ind] == '+')
		r_ind++;
	while (str[r_ind] >= '0' && str[r_ind] <= '9')
	{
		final_num = (final_num * 10) + (str[r_ind] - '0');
		r_ind++;
	}
	return (final_num);
}

static int	get_neg(const char *s, int index)
{
	int	ref;

	ref = index;
	if (s[ref] == '-')
	{
		if ((s[ref + 1] <= '9') && (s[ref + 1] >= '0'))
			return (1);
		else
			return (2);
	}
	else if (s[ref] == '+')
	{
		if (s[ref + 1] >= '0' && s[ref + 1] <= '9')
			return (0);
		else
			return (2);
	}
	else if ((s[ref] >= '0') && (s[ref] <= '9'))
		return (0);
	else
		return (2);
}

int	ft_atoi(const char *str)
{
	int		ind;
	int		neg;
	int		num;
	char	*s;

	if (!str)
		return (0);
	s = (char *)str;
	ind = 0;
	while (s[ind] == ' ' || s[ind] == '\t' || s[ind] == '\v'
		|| s[ind] == '\f' || s[ind] == '\n' || s[ind] == '\r')
		ind++;
	neg = get_neg(s, ind);
	if (neg == 2)
		return (0);
	else if (neg == 1)
	{
		num = -(get_num(s, (ind + 1)));
		return (num);
	}
	else
	{
		num = get_num(s, ind);
		return (num);
	}
}
