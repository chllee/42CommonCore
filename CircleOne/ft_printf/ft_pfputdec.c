/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfputdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 20:16:48 by chllee            #+#    #+#             */
/*   Updated: 2025/06/25 15:35:15 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

static int	get_size(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count = 1;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	write_num(int num)
{
	char	mod;

	if (num == 0)
		return ;
	write_num(num / 10);
	mod = (num % 10) + '0';
	write(1, &mod, 1);
}

int	ft_pfputdec(int num)
{
	int		count;

	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = get_size(num);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -(num);
	}
	write_num(num);
	return (count);
}
