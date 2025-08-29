/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:43:13 by chllee            #+#    #+#             */
/*   Updated: 2025/07/15 19:19:58 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>

// functions in main get_next_line file (main function operations)
char	*get_next_line(int fd);
char    *get_line(char *str, ssize_t lb);
char    *read_file(int fd, char **stash, ssize_t lb);
char	*line_in_buf(char *buf, char **stash, ssize_t lb);

// functions in utility file (small helper functions)
ssize_t	find_lb(char *str);
ssize_t	str_len(char *str);
char	*return_stash(char **stash);
char	*str_join(char **stash, char *line);
char	*update_stash(char **stash, char *buf, ssize_t lb);

#endif