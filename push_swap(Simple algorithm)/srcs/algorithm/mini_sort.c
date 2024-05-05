/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:39:28 by kjs               #+#    #+#             */
/*   Updated: 2023/02/13 11:37:23 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	small_sort(t_node **a, t_node **b, int total)
{
	if (is_sorted(a))
		return ;
	if (total == 2 || total == 3)
		sort_three(a);
	if (total == 4)
		sort_four(a, b);
	if (total == 5)
		sort_five(a, b);
}

void	sort_three(t_node **a)
{
	if (!is_sorted(a) && (*a)->n > (*a)->next->n && (*a)->n > (*a)->prev->n)
		ra(a);
	if (!is_sorted(a) && !((*a)->prev->n > (*a)->n \
	&& (*a)->prev->n > (*a)->next->n))
		rra(a);
	if (!is_sorted(a) && (*a)->n > (*a)->next->n)
		sa(a);
}

void	sort_four(t_node **a, t_node **b)
{
	int	cnt;

	cnt = 1;
	while (cnt)
	{
		if ((*a)->n == 1)
		{
			pb(a, b);
			cnt--;
		}
		else
			ra(a);
	}
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_node **a, t_node **b)
{
	int	cnt;

	cnt = 2;
	while (cnt)
	{
		if ((*a)->n == 1 || (*a)->n == 5)
		{
			pb(a, b);
			cnt--;
		}
		else
			ra(a);
	}
	sort_three(a);
	if ((*b)->n == 1)
	{
		pa(a, b);
		pa(a, b);
		ra(a);
		return ;
	}
	pa(a, b);
	ra(a);
	pa(a, b);
}

int	is_sorted(t_node **a)
{
	t_node	*node;

	node = (*a);
	while (1)
	{
		if (node->next == (*a))
			break ;
		if (node->n > node->next->n)
			return (0);
		node = node->next;
	}
	return (1);
}
