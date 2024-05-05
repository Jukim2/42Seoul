/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:27:32 by jukim2            #+#    #+#             */
/*   Updated: 2023/07/09 13:03:38 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

long long	grab_fork(t_phil *philo, t_info *info)
{
	int				left_fork;
	int				right_fork;

	left_fork = philo->num;
	right_fork = philo->num + 1;
	if (philo->num + 1 == info->head_cnt)
		right_fork = 0;
	if (philo->num % 2 == 0)
		return (lock_fork(philo, info, right_fork, left_fork));
	else
		return (lock_fork(philo, info, left_fork, right_fork));
}

long long	lock_fork(t_phil *philo, t_info *info, \
					int first_fork, int second_fork)
{
	if (!grab_first_fork(philo, info, first_fork))
		return (0);
	if (is_one_fork(philo, first_fork, second_fork))
		return (0);
	if (!grab_second_fork(philo, info, first_fork, second_fork))
		return (0);
	return (1);
}

void	unlock_fork(t_phil *philo, t_info *info)
{
	int		left_fork;
	int		right_fork;

	left_fork = philo->num;
	right_fork = philo->num + 1;
	if (philo->num + 1 == info->head_cnt)
		right_fork = 0;
	if (philo->num % 2 == 0)
	{
		pthread_mutex_unlock(&(info->fork[right_fork]));
		pthread_mutex_unlock(&(info->fork[left_fork]));
	}
	else
	{
		pthread_mutex_unlock(&(info->fork[left_fork]));
		pthread_mutex_unlock(&(info->fork[right_fork]));
	}
}

int	grab_first_fork(t_phil *philo, t_info *info, int first_fork)
{
	pthread_mutex_lock(&(info->fork[first_fork]));
	pthread_mutex_lock(&(philo->info->print_mutex));
	if (i_am_dead(philo))
	{
		pthread_mutex_unlock(&(info->fork[first_fork]));
		pthread_mutex_unlock(&(philo->info->print_mutex));
		return (0);
	}
	printf("%lld %d has taken a fork\n", \
		get_time() - info->start_time, philo->num + 1);
	pthread_mutex_unlock(&(philo->info->print_mutex));
	return (1);
}

long long	grab_second_fork(t_phil *philo, t_info *info, \
	int first_fork, int second_fork)
{
	long long	t;

	pthread_mutex_lock(&(info->fork[second_fork]));
	pthread_mutex_lock(&(philo->info->print_mutex));
	t = get_time();
	if (i_am_dead(philo))
	{
		pthread_mutex_unlock(&(info->fork[first_fork]));
		pthread_mutex_unlock(&(info->fork[second_fork]));
		pthread_mutex_unlock(&(philo->info->print_mutex));
		return (0);
	}
	printf("%lld %d has taken a fork\n", t - info->start_time, philo->num + 1);
	pthread_mutex_unlock(&(philo->info->print_mutex));
	return (t);
}
