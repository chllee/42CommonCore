/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfputadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:12:55 by chllee            #+#    #+#             */
/*   Updated: 2025/06/25 18:59:42 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "libftprintf.h"

int	ft_pfputadd(unsigned int x, char type)
{
	int			len;
	uintptr_t	p;

	if (x == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	p = (uintptr_t)x;
	if (type == 'x')
		len = ft_phex(p);
	else if (type == 'X')
		len = ft_uphex(p);
	else
		len = 0;
	return (len);
}
