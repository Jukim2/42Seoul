/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:27:52 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:38:19 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int	pick_3_rr(t_node **a, t_node **b, int target)
{
	int		r1;
	int		r2;
	int		r3;

	r1 = cal_rotation(b, target);
	r2 = cal_rotation(b, target - 1);
	r3 = cal_rotation(b, target - 2);
	target -= r3;
	while (target--)
		rrb(b);
	pa(a, b);
	target = (r3 - r2);
	while (target--)
		rrb(b);
	pa(a, b);
	ra(a);
	target = (r2 - r1);
	while (target--)
		rrb(b);
	pa(a, b);
	sa(a);
	rra(a);
	sa(a);
	return (1);
}

int	pick_2_rr(t_node **a, t_node **b, int target)
{
	int		r1;
	int		r2;

	r1 = cal_rotation(b, target);
	r2 = cal_rotation(b, target - 1);
	target -= r2;
	while (target--)
		rrb(b);
	pa(a, b);
	target = (r2 - r1);
	while (target--)
		rrb(b);
	pa(a, b);
	sa(a);
	return (1);
}

void	pick_1_rr(t_node **a, t_node **b, int target)
{
	while (target--)
		rrb(b);
	pa(a, b);
}
