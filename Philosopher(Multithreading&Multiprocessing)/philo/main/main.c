/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:02:17 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/17 13:08:26 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <pthread.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_info		*info;
	t_phil		**philo_list;
	pthread_t	monitor_id;

	if (argc < 5)
	{
		printf("Error : Need more argument\n");
		return (0);
	}
	info = set_info(argc, argv);
	if (!info)
		return (0);
	philo_list = make_philosophers(info);
	if (!philo_list)
		return (0);
	if (!make_monitor_thread(philo_list, info, &monitor_id))
		return (0);
	manage_thread(philo_list, info, monitor_id);
	clean_program(philo_list, info, info->head_cnt);
}

void	manage_thread(t_phil **philo_list, t_info *info, pthread_t monitor_id)
{
	int	idx;

	idx = 0;
	while (idx < info->head_cnt)
		pthread_join(philo_list[idx++]->id, NULL);
	pthread_join(monitor_id, NULL);
}
