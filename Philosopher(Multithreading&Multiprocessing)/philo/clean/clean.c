/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:28:35 by kjs               #+#    #+#             */
/*   Updated: 2023/07/09 13:02:02 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <unistd.h>
#include <stdlib.h>

void	terminate_program(t_phil **philo_list, t_info *info, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
		pthread_detach(philo_list[i]->id);
	pthread_mutex_lock(&(info->err_mutex));
	info->err = 1;
	pthread_mutex_unlock(&(info->err_mutex));
	usleep(10000);
	clean_program(philo_list, info, idx);
}

void	clean_program(t_phil **philo_list, t_info *info, int idx)
{
	freedom_to_philosophers(philo_list, idx);
	destroy_mutex(info, info->head_cnt);
	free_info(info);
}

void	freedom_to_philosophers(t_phil **philo_list, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
		free(philo_list[i++]);
	free(philo_list);
}

void	free_info(t_info *info)
{
	if (info->t_last_meal)
		free(info->t_last_meal);
	if (info->meal_taken)
		free(info->meal_taken);
	if (info->fork)
		free(info->fork);
	if (info->meal_mutex)
		free(info->meal_mutex);
	if (info->end_mutex)
		free(info->end_mutex);
	if (info->is_end)
		free(info->is_end);
	free(info);
}
