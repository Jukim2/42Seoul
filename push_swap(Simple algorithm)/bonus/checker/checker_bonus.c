/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:48:34 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 12:09:10 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_bonus.h"
#include "../../includes/libft.h"

void	read_command(t_node **a, t_node **b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (!apply_command(a, b, cmd))
		{
			write(0, "Error\n", 6);
			return ;
		}
		cmd = get_next_line(0);
	}
	if (!is_sorted(a) || *b)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

int	apply_command(t_node **a, t_node **b, char *cmd)
{
	int	len;

	len = ft_strlen(cmd);
	if (len < 3 || len > 4)
		return (0);
	if (len == 3)
		return (check_short_cmd(a, b, cmd));
	if (len == 4)
		return (check_long_cmd(a, b, cmd));
	return (0);
}

int	check_short_cmd(t_node **a, t_node **b, char *cmd)
{
	if (!ft_strncmp(cmd, "ra\n", 12))
		ra(a);
	else if (!ft_strncmp(cmd, "rb\n", 12))
		rb(b);
	else if (!ft_strncmp(cmd, "rr\n", 12))
		rr(a, b);
	else if (!ft_strncmp(cmd, "sa\n", 12))
		sa(a);
	else if (!ft_strncmp(cmd, "sb\n", 12))
		sb(b);
	else if (!ft_strncmp(cmd, "ss\n", 12))
		ss(a, b);
	else if (!ft_strncmp(cmd, "pa\n", 12))
		pa(a, b);
	else if (!ft_strncmp(cmd, "pb\n", 12))
		pb(a, b);
	else
		return (0);
	return (1);
}

int	check_long_cmd(t_node **a, t_node **b, char *cmd)
{
	if (!ft_strncmp(cmd, "rra\n", 16))
		rra(a);
	else if (!ft_strncmp(cmd, "rrb\n", 16))
		rrb(b);
	else if (!ft_strncmp(cmd, "rrr\n", 16))
		rrr(a, b);
	else
		return (0);
	return (1);
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
