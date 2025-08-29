/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:43:25 by chllee            #+#    #+#             */
/*   Updated: 2025/06/23 20:04:26 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Re-create a printf function that does the following conversions:
	- c : SINGLE CHARACTER (char type default promoted to int)
	- s : STRING
	- p : POINTER
	- d : DECIMAL (BASE 10)
	- i : INTEGER (BASE 10)
	- u : UNSIGNED DECIMAL (BASE 10)
	- x : LOWERCASE HEXADECIMAL (BASE 16)
	- X : UPPERCASE HEXADECIMAL (BASE 16)
	- % : Print a "%" character
*/

#include <unistd.h>
#include "libftprintf.h"

static int	ft_cvsn(char type, va_list args)
{
	int		count;

	count = 0;
	if (type == 'c')
		count = ft_pfputchar(va_arg(args, int));
	else if (type == 's')
		count = ft_pfputstr(va_arg(args, char *));
	else if (type == 'p')
		count = ft_pfputptr(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		count = ft_pfputdec(va_arg(args, int));
	else if (type == 'u')
		count = ft_pfputunsint(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count = ft_pfputadd(va_arg(args, unsigned int), type);
	else if (type == '%')
		count = ft_pfpercent();
	return (count);
}

static int	ft_checkstr(const char *f_str, va_list args)
{
	int	count;

	count = 0;
	while (*f_str != '\0')
	{
		if (*f_str == '%')
		{
			if (ft_strchr("cspdiuxX%", *(f_str + 1)))
				count = count + ft_cvsn(*(f_str + 1), args);
			else
				return (0);
			f_str++;
		}
		else
		{
			write(1, f_str, 1);
			count++;
		}
		f_str++;
	}
	return (count);
}

int	ft_printf(const char *f_str, ...)
{
	va_list		args;
	int			count;

	va_start(args, f_str);
	count = ft_checkstr(f_str, args);
	va_end(args);
	return (count);
}
