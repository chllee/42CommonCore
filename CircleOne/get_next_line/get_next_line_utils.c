/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:43:32 by chllee            #+#    #+#             */
/*   Updated: 2025/07/15 20:13:34 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// returns INDEX of \n or -1 if no new line is found
ssize_t	find_lb(char *str)
{
	ssize_t	count;

	if (!str)
		return (-1);
	count = 0;
	while (*str)
	{
		if (*str == '\n')
			return (count);
		count++;
		str++;
	}
	return (-1);
}

// get length of string
ssize_t	str_len(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

// basically str_dup function when the stash needs to be copied and free-ed
char	*return_stash(char **stash)
{
	ssize_t	stashlen;
	ssize_t	ind;
	char	*line;

	stashlen = str_len(*stash);
	line = malloc(stashlen + 1);
	if (!line)
		return (NULL);
	ind = 0;
	while (ind < stashlen && *stash)
	{
		line[ind] = (*stash)[ind];
		ind++;
	}
	line[ind] = '\0';
	free(*stash);
	(*stash) = NULL;
	return (line);
}

char	*str_join(char **stash, char *line)
{
	ssize_t	l_ind;
	ssize_t nl_ind;
	char	*newln;

	newln = malloc((str_len(line) + str_len(*stash) + 1) * sizeof(char));
	if (!newln)
		return (NULL);
	nl_ind = 0;
	while ((*stash) && ((*stash)[nl_ind]))
	{
		newln[nl_ind] = (*stash)[nl_ind];
		nl_ind++;
	}
	l_ind = 0;
	while (line[l_ind])
	{
		newln[nl_ind + l_ind] = line[l_ind];
		l_ind++;
	}
	newln[nl_ind + l_ind] = '\0';
	if (*stash)
		free(*stash);
	(*stash) = NULL;
	return (newln);
}

// clear original stash and update with new buffer remainder
char	*update_stash(char **stash, char *buf, ssize_t lb)
{
	char	*new_line;
	ssize_t	buf_len;
	ssize_t	new_len;
	ssize_t	ln_ind;

	buf_len = str_len(buf);
	new_len = buf_len - lb - 1;
	if (new_len <= 0)
	{
		free(*stash);
		return (NULL);
	}
	new_line = malloc(new_len + 1);
	if (!new_line)
		return (NULL);
	ln_ind = 0;
	while (buf[lb + 1 + ln_ind])
	{
		new_line[ln_ind] = buf[ln_ind + lb + 1];
		ln_ind++;
	}
	new_line[ln_ind] = '\0';
	if (*stash)
		free(*stash);
	return (new_line);
}
