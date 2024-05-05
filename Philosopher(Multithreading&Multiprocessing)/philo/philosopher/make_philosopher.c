/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:32:59 by jukim2            #+#    #+#             */
/*   Updated: 2023/07/04 17:35:57 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>
#include <unistd.h>

t_phil	**make_philosophers(t_info *info)
{
	int		idx;
	t_phil	**philo_list;
	t_phil	*philosopher;

	idx = 0;
	philo_list = malloc(sizeof(t_phil *) * info->head_cnt);
	if (!philo_list)
		return (NULL);
	while (idx < info->head_cnt)
	{
		philosopher = birth(info, idx);
		if (!philosopher)
		{
			terminate_program(philo_list, info, idx);
			return (NULL);
		}
		if (pthread_create(&(philosopher->id), 0, routine, (void *)philosopher))
		{
			terminate_program(philo_list, info, idx + 1);
			return (NULL);
		}
		philo_list[idx++] = philosopher;
		usleep(5);
	}
	return (philo_list);
}

t_phil	*birth(t_info *info, int idx)
{
	t_phil	*philosopher;

	philosopher = malloc(sizeof(t_phil));
	if (!philosopher)
		return (NULL);
	philosopher->num = idx;
	philosopher->info = info;
	return (philosopher);
}
