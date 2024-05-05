/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:06:19 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:41:14 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int	move_to_b(t_node **a, t_node **b, int total)
{
	int		pivot;
	int		division;
	int		prev_pivot;

	pivot = 0;
	division = 4;
	if (total < 300)
		division = 2;
	while (1)
	{
		prev_pivot = pivot;
		pivot = pivot + (total - pivot) / division;
		move_less_than_pivot(a, b, pivot, prev_pivot);
		if (pivot == prev_pivot)
			break ;
	}
	return (pivot);
}

void	move_less_than_pivot(t_node **a, t_node**b, int pivot, int prev_pivot)
{
	while (1)
	{
		if ((*a)->n <= pivot - (pivot - prev_pivot) / 2)
			pb(a, b);
		else if ((*a)->n <= pivot)
		{
			pb(a, b);
			if ((*a)->n > pivot)
				rr(a, b);
			else
				rb(b);
		}
		else
			ra(a);
		if (pivot_end(a, pivot, prev_pivot))
			break ;
	}
}

int	pivot_end(t_node **a, int pivot, int prev_pivot)
{
	t_node	*node;

	node = (*a);
	(void)prev_pivot;
	while (1)
	{
		if (node->n <= pivot)
			return (0);
		if (node->next->n == (*a)->n)
			break ;
		node = node->next;
	}
	return (1);
}
