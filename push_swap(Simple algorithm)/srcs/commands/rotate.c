/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:56:35 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:45:21 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/libft.h"

void	ra(t_node **a)
{
	t_node	*node;

	node = *a;
	if (node && node->next)
		*a = node->next;
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	t_node	*node;

	node = *b;
	if (node && node->next)
		*b = node->next;
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	t_node	*node;

	node = *a;
	if (node && node->next)
		*a = node->next;
	node = *b;
	if (node && node->next)
		*b = node->next;
	ft_printf("rr\n");
}
