/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:29:51 by chllee            #+#    #+#             */
/*   Updated: 2025/06/12 17:15:32 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if ((!lst) || (!new))
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}
