/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:43:05 by chllee            #+#    #+#             */
/*   Updated: 2025/07/15 14:29:17 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*path = "./file.txt";
	char	*line;

	fd = open(path, O_RDONLY);
	
	line = get_next_line(fd);
	if (!line)
		printf("Something wrong reading line\n \n");
	else
		printf("Line found: %s\n\n", line);
	free(line);

	line = get_next_line(fd);
	if (!line)
		printf("Something wrong reading line\n \n");
	else
		printf("Line found: %s\n\n", line);
	free(line);

	line = get_next_line(fd);
	if (!line)
		printf("Something wrong reading line\n \n");
	else
		printf("Line found: %s\n", line);
	free(line);

	line = get_next_line(fd);
	if (!line)
		printf("Something wrong reading line\n \n");
	else
		printf("Line found: %s\n\n", line);
	free(line);

	return (0);
}