/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:34:41 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 12:09:28 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack_bonus.h"

int	main(int argc, char *argv[])
{
	int		total;
	t_num	*num_list;
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		return (0);
	a = 0;
	b = 0;
	num_list = 0;
	get_argument(&num_list, argc, argv);
	total = ft_num_lst_len(num_list);
	num_list = convt_list(num_list, total);
	make_stack(&a, num_list);
	free_num_lst(&num_list);
	read_command(&a, &b);
}
