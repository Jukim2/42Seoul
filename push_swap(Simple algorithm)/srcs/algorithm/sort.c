/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 01:34:28 by kjs               #+#    #+#             */
/*   Updated: 2023/02/13 12:22:09 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/libft.h"

void	quick_sort(t_node **a, t_node **b, int total)
{
	int	last_pivot;

	if (is_sorted(a))
		return ;
	last_pivot = move_to_b(a, b, total);
	sort_three(a);
	move_to_a(a, b, total, total - last_pivot);
}
