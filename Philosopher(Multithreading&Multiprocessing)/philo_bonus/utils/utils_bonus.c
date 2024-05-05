/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:02:04 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 13:52:48 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
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

void	count_time(t_info *info, long duration, long long start_time)
{
	long long		current_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	current_time = time.tv_sec * 1000LL + time.tv_usec / 1000LL;
	while (current_time - start_time < duration)
	{
		gettimeofday(&time, NULL);
		current_time = time.tv_sec * 1000LL + time.tv_usec / 1000LL;
		if (is_dead(info))
			return ;
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

void	print_msg(t_info *info, t_sem *semaphores, char *action)
{
	if (is_dead(info))
	{
		sem_wait(semaphores->print_sem);
		printf("%lld %d died\n", get_time() - info->t_start, \
			info->philo_num + 1);
		sem_post(semaphores->end_sem);
		return ;
	}
	sem_wait(semaphores->print_sem);
	printf("%lld %d %s\n", get_time() - info->t_start, \
		info->philo_num + 1, action);
	sem_post(semaphores->print_sem);
}
