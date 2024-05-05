/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:23:52 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 13:51:10 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void	start_routine(t_info *info, t_sem *semaphores, int philo_num)
{
	t_com	thread_arg;

	set_thread_arg(&thread_arg, info, semaphores, philo_num);
	if (pthread_create(&(info->tid), NULL, monitor_death, &thread_arg))
		exit_program(info, semaphores, 1);
	sem_wait(semaphores->meal_update_sem[philo_num]);
	info->t_last_meal = info->t_start;
	sem_post(semaphores->meal_update_sem[philo_num]);
	if (philo_num % 2 == 0)
		usleep(100);
	while (1)
	{
		philo_eat(info, semaphores);
		philo_sleep(info, semaphores);
		philo_think(info, semaphores);
	}
}

void	set_thread_arg(t_com *thread_arg, t_info *info, \
		t_sem *semaphores, int philo_num)
{
	thread_arg->info = info;
	thread_arg->semaphores = semaphores;
	thread_arg->philo_num = philo_num;
}

void	end_dining(t_info *info, t_sem *semaphores, int philo_num)
{
	sem_wait(semaphores->print_sem);
	printf("%lld %d died\n", get_time() - info->t_start, philo_num + 1);
	sem_post(semaphores->end_sem);
}
