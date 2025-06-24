/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:14:34 by chllee            #+#    #+#             */
/*   Updated: 2025/06/11 22:17:19 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*tmp;

	if (!lst)
		return (0);
	count = 1;
	tmp = lst->next;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
