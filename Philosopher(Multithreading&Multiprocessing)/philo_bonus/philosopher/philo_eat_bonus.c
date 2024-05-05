/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:22:47 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 11:30:21 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	philo_eat(t_info *info, t_sem *semaphores)
{
	get_forks(info, semaphores);
	dine(info, semaphores);
	put_fork(semaphores);
	info->dine_cnt++;
	if (info->min_dine && info->dine_cnt >= info->min_dine)
	{
		sem_post(semaphores->meal_finished_sem);
		info->min_dine = 0;
	}
}

void	get_forks(t_info *info, t_sem *semaphores)
{
	sem_wait(semaphores->fork_auth_sem);
	grab_fork(info, semaphores);
	grab_fork(info, semaphores);
}

void	grab_fork(t_info *info, t_sem *semaphores)
{
	sem_wait(semaphores->fork_sem);
	print_msg(info, semaphores, "has taken a fork");
}

void	dine(t_info *info, t_sem *semaphores)
{
	const long long	eat_time = get_time();

	print_msg(info, semaphores, "is eating");
	sem_wait(semaphores->meal_update_sem[info->philo_num]);
	info->t_last_meal = eat_time;
	sem_post(semaphores->meal_update_sem[info->philo_num]);
	count_time(info, info->t_eat, eat_time);
}

void	put_fork(t_sem *semaphores)
{
	sem_post(semaphores->fork_sem);
	sem_post(semaphores->fork_sem);
	sem_post(semaphores->fork_auth_sem);
}
