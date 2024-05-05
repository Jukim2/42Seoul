/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:56:04 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:47:47 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_bonus.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*node;

	node = *b;
	if (!node)
		return ;
	cdll_addfront(a, cdll_new_node((*b)->n));
	cdll_deltop(b);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*node;

	node = *a;
	if (!node)
		return ;
	cdll_addfront(b, cdll_new_node((*a)->n));
	cdll_deltop(a);
}
