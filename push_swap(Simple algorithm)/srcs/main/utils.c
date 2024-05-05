/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:56:35 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:46:14 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/libft.h"

int	ps_atoi(int *flag, const char *str)
{
	long long	num;
	long long	is_minus;

	num = 0;
	is_minus = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		is_minus = *(str++) - '+';
	while ('0' <= *str && *str <= '9')
	{
		num *= 10;
		num += *(str++) - '0';
		if ((!is_minus && num > INT_MAX) || (is_minus && num > -INT_MIN))
			*flag = 0;
	}
	if (*str && (*str < '0' || *str > '9'))
		*flag = 0;
	if (is_minus)
		num *= -1;
	return (num);
}

void	free_num_lst(t_num **num_list)
{
	t_num	*prev_node;
	t_num	*node;

	node = *num_list;
	if (!node)
		return ;
	while (node->next)
	{
		prev_node = node;
		node = node->next;
		free(prev_node);
	}
	free(node);
}

void	free_d_str(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_stack(t_node *a, int total)
{
	int		i;
	t_node	*node;
	t_node	*prev_node;

	i = 0;
	node = a;
	while (i < total)
	{
		prev_node = node;
		node = node->next;
		free(prev_node);
		i++;
	}
}
