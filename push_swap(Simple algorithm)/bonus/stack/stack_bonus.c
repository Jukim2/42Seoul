/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:24:17 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:48:21 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/stack_bonus.h"

t_node	*cdll_new_node(int num)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->n = num;
	node->next = node;
	node->prev = node;
	return (node);
}

void	cdll_addback(t_node **lst, t_node *node)
{
	t_node	*head;

	head = *lst;
	if (!(*lst))
		*lst = node;
	else
	{
		head->prev->next = node;
		node->prev = head->prev;
		node->next = head;
		head->prev = node;
	}
}

void	cdll_addfront(t_node **lst, t_node *node)
{
	cdll_addback(lst, node);
	*lst = (*lst)->prev;
}

void	cdll_deltop(t_node **lst)
{
	t_node	*node;

	if (!(*lst))
		return ;
	node = *lst;
	if (node->next == node)
	{
		free(node);
		(*lst) = 0;
		return ;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	*lst = node->next;
	free (node);
}

void	make_stack(t_node **a, t_num *num_list)
{
	while (num_list)
	{
		cdll_addback(a, cdll_new_node(num_list->num));
		num_list = num_list->next;
	}
}
