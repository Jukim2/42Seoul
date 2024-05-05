/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:27:37 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:37:57 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int	pick_3_r(t_node **a, t_node **b, int target)
{
	int		r1;
	int		r2;
	int		r3;

	r1 = cal_rotation(b, target);
	r2 = cal_rotation(b, target - 1);
	r3 = cal_rotation(b, target - 2);
	target = r2 - r3 - 1;
	while (r3--)
		rb(b);
	pa(a, b);
	while (target--)
		rb(b);
	pa(a, b);
	ra(a);
	target = r1 - r2 - 1;
	while (target--)
		rb(b);
	pa(a, b);
	sa(a);
	rra(a);
	sa(a);
	return (1);
}

int	pick_2_r(t_node **a, t_node **b, int target)
{
	int		r1;
	int		r2;

	r1 = cal_rotation(b, target);
	r2 = cal_rotation(b, target - 1);
	target = r1 - r2 - 1;
	while (r2--)
		rb(b);
	pa(a, b);
	while (target--)
		rb(b);
	pa(a, b);
	sa(a);
	return (1);
}

void	pick_1_r(t_node **a, t_node **b, int target)
{
	while (target--)
		rb(b);
	pa(a, b);
}
