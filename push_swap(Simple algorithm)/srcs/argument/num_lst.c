/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:09:24 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:44:40 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/libft.h"

t_num	*ft_num_lst_new(int num)
{
	t_num	*node;

	node = malloc(sizeof(t_num));
	node->num = num;
	node->next = 0;
	return (node);
}

void	ft_num_lst_addback(t_num **node, t_num *new)
{
	t_num	*tmp;

	tmp = (*node);
	if (!(*node))
	{
		*node = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_num_lst_len(t_num *num_list)
{
	int	cnt;

	cnt = 0;
	while (num_list)
	{
		cnt++;
		num_list = num_list->next;
	}
	return (cnt);
}
