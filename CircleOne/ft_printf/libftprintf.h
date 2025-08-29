/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:47:34 by chllee            #+#    #+#             */
/*   Updated: 2025/06/25 15:15:52 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

int	ft_phex(uintptr_t p);
int	ft_uphex(uintptr_t p);
int	ft_printf(const char *f_str, ...);
int	ft_pfputchar(char c);
int	ft_pfputstr(char *str);
int	ft_pfputdec(int num);
int	ft_pfputptr(void *ptr);
int	ft_pfputadd(unsigned int x, char type);
int	ft_pfpercent(void);
int	ft_pfputunsint(unsigned int num);

#endif
