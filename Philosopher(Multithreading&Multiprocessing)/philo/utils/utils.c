/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:02:04 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 00:51:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
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
	}
	if (is_minus)
		num *= -1;
	return (num);
}

void	count_time(long long duration, long long start_time)
{
	long long		current_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	current_time = time.tv_sec * 1000LL + time.tv_usec / 1000LL;
	while (current_time - start_time < duration)
	{
		gettimeofday(&time, NULL);
		current_time = time.tv_sec * 1000LL + time.tv_usec / 1000LL;
		usleep(250);
	}
}

long long	get_time(void)
{
	long long		t;
	struct timeval	time;

	gettimeofday(&time, NULL);
	t = time.tv_sec * 1000LL + time.tv_usec / 1000LL;
	return (t);
}

int	print_msg(t_phil *philo, char *action)
{
	pthread_mutex_lock(&(philo->info->print_mutex));
	if (i_am_dead(philo))
	{
		pthread_mutex_unlock(&(philo->info->print_mutex));
		return (0);
	}
	printf("%lld %d is %s\n", get_time() - philo->info->start_time, \
		philo->num + 1, action);
	pthread_mutex_unlock(&(philo->info->print_mutex));
	return (1);
}

int	i_am_dead(t_phil *philo)
{
	pthread_mutex_lock(&(philo->info->end_mutex[philo->num]));
	if (philo->info->is_end[philo->num] == 1)
	{
		pthread_mutex_unlock(&(philo->info->end_mutex[philo->num]));
		return (1);
	}
	pthread_mutex_unlock(&(philo->info->end_mutex[philo->num]));
	return (0);
}
