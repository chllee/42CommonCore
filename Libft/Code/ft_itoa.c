/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:57:23 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:00:08 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_size(int n)
{
	int	count;
	int	temp;

	count = 0;
	temp = n;
	if (temp < 0)
	{
		count = 1;
		temp = temp * (-1);
	}
	while (temp > 0)
	{
		temp = temp / 10;
		count++;
	}
	return (count);
}

static void	get_string(int n, int start, int digits, char *rtn)
{
	int	temp_ind;
	int	temp_n;

	temp_ind = digits - 1;
	temp_n = n;
	while (temp_ind >= start)
	{
		rtn[temp_ind] = (temp_n % 10) + '0';
		temp_n = temp_n / 10;
		temp_ind--;
	}
	rtn[digits] = '\0';
}

static char	*conv(int n)
{
	int		digits;
	char	*rtn;

	digits = get_size(n);
	rtn = (char *)malloc(sizeof(char) * (digits + 1));
	if (!rtn)
		return (NULL);
	if (n < 0)
	{
		rtn[0] = '-';
		get_string(-n, 1, digits, rtn);
	}
	else
		get_string(n, 0, digits, rtn);
	return (rtn);
}

char	*ft_itoa(int n)
{
	char	*rtn;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
	{
		rtn = (char *)malloc(sizeof(char) * 2);
		if (!rtn)
			return (NULL);
		rtn[0] = '0';
		rtn[1] = '\0';
		return (rtn);
	}
	rtn = conv(n);
	return (rtn);
}
