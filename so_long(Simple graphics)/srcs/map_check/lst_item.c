/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:06:08 by kjs               #+#    #+#             */
/*   Updated: 2023/01/30 10:55:02 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../../includes/game.h"

t_graph	*ft_lstnew_item(int idx)
{
	t_graph	*item;

	item = ft_calloc(1, sizeof(t_graph));
	item->idx = idx;
	item->next = NULL;
	return (item);
}

void	ft_lstadd_item(t_graph **lst, t_graph *new)
{
	t_graph	*node;

	node = *lst;
	if (node == 0)
	{
		*lst = new;
		return ;
	}
	while (node -> next != 0)
	{
		node = node -> next;
	}
	node -> next = new;
}
