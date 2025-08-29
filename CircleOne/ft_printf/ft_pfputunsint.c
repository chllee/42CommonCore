/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfputunsint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:11:46 by chllee            #+#    #+#             */
/*   Updated: 2025/06/25 15:35:38 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

static int	get_size(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	write_num(unsigned int num)
{
	char	mod;

	if (num == 0)
		return ;
	write_num(num / 10);
	mod = (num % 10) + '0';
	write(1, &mod, 1);
}

int	ft_pfputunsint(unsigned int num)
{
	int		count;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = get_size(num);
	write_num(num);
	return (count);
}
