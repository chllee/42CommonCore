/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:44:20 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:05:26 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int		ind;
	char	line;

	ind = 0;
	while (s[ind] != '\0')
	{
		write(fd, &s[ind], 1);
		ind++;
	}
	line = '\n';
	write(fd, &line, 1);
}
