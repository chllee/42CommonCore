/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uphex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:33:46 by chllee            #+#    #+#             */
/*   Updated: 2025/06/25 19:05:42 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "libftprintf.h"

static int	get_size(uintptr_t p)
{
	int	count;

	count = 0;
	while (p > 0)
	{
		count++;
		p /= 16;
	}
	return (count);
}

static void	write_hex(uintptr_t p, const char *hex)
{
	int	mod;

	if (p == 0)
		return ;
	write_hex((p / 16), hex);
	mod = p % 16;
	write(1, &hex[mod], 1);
}

int	ft_uphex(uintptr_t p)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	write_hex(p, hex);
	return (get_size(p));
}
