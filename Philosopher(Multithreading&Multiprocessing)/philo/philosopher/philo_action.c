/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:45:02 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 00:55:15 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	philo_eat(t_phil *philo)
{
	long long		action_time;

	if (!grab_fork(philo, philo->info))
		return (0);
	action_time = get_time();
	if (!print_msg(philo, "eating"))
	{
		unlock_fork(philo, philo->info);
		return (0);
	}
	update_meal_information(philo, action_time);
	count_time(philo->info->t_eat, action_time);
	unlock_fork(philo, philo->info);
	return (1);
}

int	philo_sleep(t_phil *philo)
{
	long long		action_time;

	action_time = get_time();
	if (!print_msg(philo, "sleeping"))
		return (0);
	count_time(philo->info->t_sleep, action_time);
	return (1);
}

int	philo_think(t_phil *philo)
{
	if (!print_msg(philo, "thinking"))
		return (0);
	usleep(200);
	return (1);
}

void	update_meal_information(t_phil *philo, long long action_time)
{
	pthread_mutex_lock(&(philo->info->meal_mutex[philo->num]));
	philo->info->t_last_meal[philo->num] = action_time;
	(philo->info->meal_taken[philo->num])++;
	pthread_mutex_unlock(&(philo->info->meal_mutex[philo->num]));
}
