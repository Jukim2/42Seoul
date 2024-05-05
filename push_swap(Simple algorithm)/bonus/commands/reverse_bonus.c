/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:27:23 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:47:55 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_bonus.h"

void	rra(t_node **a)
{
	t_node	*node;

	node = *a;
	if (node && node->prev)
		*a = node->prev;
}

void	rrb(t_node **b)
{
	t_node	*node;

	node = *b;
	if (node && node->prev)
		*b = node->prev;
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
}
