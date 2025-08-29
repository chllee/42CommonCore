/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:16:28 by chllee            #+#    #+#             */
/*   Updated: 2025/06/25 19:19:21 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "libftprintf.h"

int	get_size(uintptr_t p)
{
	int	digits;

	digits = 0;
	while (p > 0)
	{
		digits++;
		p /= 16;
	}
	return (digits);
}

void	write_hex(uintptr_t p, char *set)
{
	int	ind;

	if (p == 0)
		return ;
	write_hex((p / 16), set);
	ind = (p % 16);
	write(1, &set[ind], 1);
}

int	ft_phex(uintptr_t p)
{
	char	*hex;

	hex = "0123456789abcdef";
	write_hex(p, hex);
	return (get_size(p));
}

/*
#include <stdio.h>
int	main(void)
{
	int		res;
	char		str[] = "this is a str";
	void		*t;
	uintptr_t	p;

	t = str;
	p = (uintptr_t)t;
	// res = ft_phex(p);
	printf("\n");
	printf("my function: \n");
	printf("%d\n", ft_phex(p));
	printf("og function: \n");
	printf("%p\n", t);

	return 0;
}
*/
