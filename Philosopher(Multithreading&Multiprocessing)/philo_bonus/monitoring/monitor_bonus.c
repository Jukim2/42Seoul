/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:16:22 by kjs               #+#    #+#             */
/*   Updated: 2023/08/22 00:40:22 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <stdio.h>

void	make_monitor(t_info *info, t_sem *semaphores)
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid == CHILD)
	{
		while (i < info->head_cnt)
		{
			sem_wait(semaphores->meal_finished_sem);
			i++;
		}
		sem_wait(semaphores->print_sem);
		sem_post(semaphores->end_sem);
	}
	else if (pid == FAIL)
	{
		clear_semaphores(semaphores, info->sem_names, info->head_cnt);
		exit_program(info, semaphores, 1);
	}
	else
	{
		info->pid[info->head_cnt] = pid;
	}
}

void	*monitor_death(void *thread_arg)
{
	t_info	*info;
	t_sem	*semaphores;
	int		philo_num;

	info = ((t_com *)thread_arg)->info;
	semaphores = ((t_com *)thread_arg)->semaphores;
	philo_num = ((t_com *)thread_arg)->philo_num;
	while (1)
	{
		sem_wait(semaphores->meal_update_sem[philo_num]);
		if (info->t_last_meal
			&& get_time() - info->t_last_meal > info->t_die)
		{
			end_dining(info, semaphores, philo_num);
			break ;
		}
		sem_post(semaphores->meal_update_sem[philo_num]);
		usleep(200);
	}
	return (NULL);
}

int	is_dead(t_info *info)
{
	if (get_time() - info->t_last_meal > info->t_die)
		return (1);
	else
		return (0);
}
