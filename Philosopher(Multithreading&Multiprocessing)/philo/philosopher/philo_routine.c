/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:23:52 by jukim2            #+#    #+#             */
/*   Updated: 2023/07/09 13:03:45 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <sys/time.h>
#include <unistd.h>

void	*routine(void *philosopher)
{
	t_phil	*philo;

	philo = (t_phil *)philosopher;
	if (philo->num + 1 == philo->info->head_cnt)
		set_start_time(philo);
	while (1)
	{
		if (is_err(philo))
			return (0);
		pthread_mutex_lock(&(philo->info->ready_mutex));
		if (philo->info->start_time)
		{
			pthread_mutex_unlock(&(philo->info->ready_mutex));
			break ;
		}
		pthread_mutex_unlock(&(philo->info->ready_mutex));
	}
	if (philo->num % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (!philo_eat(philo) || !philo_sleep(philo) || !philo_think(philo))
			break ;
	}
	return (0);
}

void	set_start_time(t_phil *philo)
{
	int				idx;
	long long		start_time;
	struct timeval	time;

	idx = 0;
	gettimeofday(&time, NULL);
	start_time = time.tv_sec * 1000LL + time.tv_usec / 1000LL;
	while (idx < philo->info->head_cnt)
	{
		pthread_mutex_lock(&(philo->info->meal_mutex[idx]));
		philo->info->t_last_meal[idx] = start_time;
		pthread_mutex_unlock(&(philo->info->meal_mutex[idx++]));
	}
	pthread_mutex_lock(&(philo->info->ready_mutex));
	philo->info->start_time = start_time;
	pthread_mutex_unlock(&(philo->info->ready_mutex));
}

int	is_err(t_phil *philo)
{
	pthread_mutex_lock(&(philo->info->err_mutex));
	if (philo->info->err)
	{
		pthread_mutex_unlock(&(philo->info->err_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(philo->info->err_mutex));
	return (0);
}
