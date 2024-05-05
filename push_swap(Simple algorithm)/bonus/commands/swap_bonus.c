/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:55:39 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:48:05 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_bonus.h"

void	sa(t_node **a)
{
	int	store;

	if (!(*a) || (*a)->next == (*a))
		return ;
	store = (*a)->n;
	(*a)->n = (*a)->next->n;
	(*a)->next->n = store;
}

void	sb(t_node **b)
{
	int	store;

	if (!(*b) || (*b)->next == (*b))
		return ;
	store = (*b)->n;
	(*b)->n = (*b)->next->n;
	(*b)->next->n = store;
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
}
