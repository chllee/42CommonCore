/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfputptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:55:45 by chllee            #+#    #+#             */
/*   Updated: 2025/06/25 15:08:29 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "libftprintf.h"

int	ft_pfputptr(void *ptr)
{
	uintptr_t	p;
	int			count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	p = (uintptr_t)ptr;
	count = ft_phex(p) + 2;
	return (count);
}
