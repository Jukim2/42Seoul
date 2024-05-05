/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:16:22 by kjs               #+#    #+#             */
/*   Updated: 2023/08/22 11:32:57 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	make_monitor_thread(t_phil **philo_list, t_info *info, \
						pthread_t *monitor_id)
{
	if (pthread_create(monitor_id, NULL, monitor_philosopher, (void *)info))
	{
		terminate_program(philo_list, info, info->head_cnt);
		return (0);
	}
	return (1);
}

void	*monitor_philosopher(void *info)
{
	while (1)
	{
		if (is_over(info, get_time()))
			break ;
		usleep(3000);
	}
	return (0);
}

int	is_over(t_info *info, long long t_now)
{
	int	idx;
	int	num_of_finsihed_eating;

	idx = 0;
	num_of_finsihed_eating = 0;
	while (idx < info->head_cnt)
	{
		pthread_mutex_lock(&(info->meal_mutex[idx]));
		if (info->t_last_meal[idx]
			&& t_now - info->t_last_meal[idx] > info->t_die)
		{
			kill_all_philosopher(info);
			print_died_msg(info, t_now, idx);
			return (1);
		}
		if (info->min_dine && info->meal_taken[idx] >= info->min_dine)
			num_of_finsihed_eating++;
		pthread_mutex_unlock(&(info->meal_mutex[idx++]));
	}
	if (num_of_finsihed_eating == info->head_cnt)
	{
		kill_all_philosopher(info);
		return (1);
	}
	return (0);
}

void	kill_all_philosopher(t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->head_cnt)
	{
		pthread_mutex_lock(&(info->end_mutex[idx]));
		(info->is_end)[idx] = 1;
		pthread_mutex_unlock(&(info->end_mutex[idx]));
		idx++;
	}
}

void	print_died_msg(t_info *info, long long t_now, int idx)
{
	pthread_mutex_lock(&(info->print_mutex));
	printf("%lld %d died\n", t_now - info->start_time, idx + 1);
	pthread_mutex_unlock(&(info->print_mutex));
	pthread_mutex_unlock(&(info->meal_mutex[idx]));
}
