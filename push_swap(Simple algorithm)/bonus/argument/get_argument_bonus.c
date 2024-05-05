/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:32:54 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:46:49 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_bonus.h"
#include "../../includes/libft.h"

void	get_argument(t_num **num_list, int argc, char *argv[])
{
	int		idx;
	char	*str;
	char	**strs;

	idx = 1;
	while (idx < argc)
	{
		str = argv[idx++];
		strs = ps_split(str);
		if (!strs)
		{
			write(0, "Error\n", 6);
			free_num_lst(num_list);
			exit(0);
		}
		put_lst(num_list, strs);
		free_d_str(strs);
	}
}

void	put_lst(t_num **num_list, char **strs)
{
	int	i;
	int	flag;
	int	atoied_num;

	i = -1;
	flag = 1;
	while (strs[++i])
	{
		atoied_num = ps_atoi(&flag, strs[i]);
		check_duplicate(atoied_num, &flag, num_list);
		if (!flag)
		{
			write(0, "Error\n", 6);
			free_d_str(strs);
			free_num_lst(num_list);
			exit(0);
		}
		ft_num_lst_addback(num_list, ft_num_lst_new(atoied_num));
	}
}

void	check_duplicate(int atoied_num, int *flag, t_num **num_list)
{
	t_num	*node;

	node = *num_list;
	while (node)
	{
		if (node->num == atoied_num)
			*flag = 0;
		node = node->next;
	}
}
