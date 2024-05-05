/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convt_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:03:36 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/12 20:09:28 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_num	*convt_list(t_num *num_list, int len)
{
	int		i;
	int		num;
	int		cnt;
	t_num	*node;
	t_num	*new_node;

	i = 0;
	new_node = 0;
	while (i < len)
	{
		node = num_list;
		cnt = 1;
		num = get_ith_num(num_list, i);
		while (node)
		{
			if (node->num != num && node->num < num)
				cnt++;
			node = node->next;
		}
		ft_num_lst_addback(&new_node, ft_num_lst_new(cnt));
		i++;
	}
	free_num_lst(&num_list);
	return (new_node);
}

int	get_ith_num(t_num *num_list, int i)
{
	while (i--)
		num_list = num_list->next;
	return (num_list->num);
}
