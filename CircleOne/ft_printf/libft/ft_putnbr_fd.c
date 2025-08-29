/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:12:28 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:06:03 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_num(int n, int fd)
{
	int	rem;
	int	curr_dig;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n == 0)
		return ;
	curr_dig = n / 10;
	rem = (n % 10) + '0';
	print_num(curr_dig, fd);
	write(fd, &rem, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else
		print_num(n, fd);
}
