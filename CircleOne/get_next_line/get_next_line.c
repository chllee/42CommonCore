/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:37:50 by chllee            #+#    #+#             */
/*   Updated: 2025/07/15 20:13:35 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

// check the stash for any existing lines before initiating a file read
char	*get_next_line(int fd)
{
	static char	*stash;
	ssize_t		lb;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lb = find_lb(stash);
	if (lb >= 0)
	{
		line = get_line(stash, lb);
		stash = update_stash(&stash, stash, lb);
		return (line);
	}
	else
	{
		line = read_file(fd, &stash, lb);
		if (!line && stash)
				line = return_stash(&stash);
		return (line);
	}
}

// only run if a line is found in string
char	*get_line(char *str, ssize_t lb)
{
	char	*line;
	ssize_t	ind;

	line = malloc(lb + 2);
	if (!line)
		return (NULL);
	ind = 0;
	while (ind <= lb)
	{
		line[ind] = str[ind];
		ind++;
	}
	line[ind] = '\0';
	return (line);
}

// only run when no line found in stash or stash is empty initially
char	*read_file(int fd, char **stash, ssize_t lb)
{
	ssize_t	bytes;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (lb < 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(buf);
			if (!(*stash))
				return (NULL);
			return (return_stash(stash));
		}
		buf[bytes] = '\0';
		lb = find_lb(buf);
		if (lb >= 0)
			return (line_in_buf(buf, stash, lb));
		(*stash) = str_join(stash, buf);
	}
	return (NULL);
}

char	*line_in_buf(char *buf, char **stash, ssize_t lb)
{
	char	*line;
	char	*buf_line;

	buf_line = get_line(buf, lb);
	line = str_join(stash, buf_line);
	(*stash) = update_stash(stash, buf, lb);
	free(buf_line);
	free(buf);
	return (line);
}
