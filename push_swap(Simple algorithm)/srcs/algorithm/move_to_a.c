/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:12:41 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:37:28 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	move_to_a(t_node **a, t_node **b, int target, int diff)
{	
	int	r;

	target -= diff;
	while (target)
	{
		r = move_target(a, b, target);
		while (r--)
			target--;
		target--;
	}
}

int	move_target(t_node **a, t_node **b, int target)
{
	int		r1;
	int		r2;
	int		r3;

	r1 = cal_rotation(b, target);
	r2 = cal_rotation(b, target - 1);
	r3 = cal_rotation(b, target - 2);
	if (r1 * 2 > target)
	{
		if (r3 > r2 && r2 > r1 && pick_3_rr(a, b, target))
			return (2);
		if (r2 > r1 && pick_2_rr(a, b, target))
			return (1);
		pick_1_rr(a, b, target - r1);
	}
	else
	{
		if (r3 < r2 && r2 < r1 && pick_3_r(a, b, target))
			return (2);
		if (r2 < r1 && pick_2_r(a, b, target))
			return (1);
		pick_1_r(a, b, r1);
	}
	return (0);
}

int	cal_rotation(t_node **b, int target)
{
	t_node	*node;
	int		cnt;

	if (target < 1)
		return (0);
	node = (*b);
	cnt = 0;
	while (1)
	{
		if (node->n == target)
			break ;
		node = node->next;
		cnt++;
	}
	return (cnt);
}
