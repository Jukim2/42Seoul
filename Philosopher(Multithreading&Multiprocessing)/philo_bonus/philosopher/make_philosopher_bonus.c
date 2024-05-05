/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philosopher_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:32:59 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 13:47:59 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <stdlib.h>
#include <unistd.h>

void	make_philosophers(t_info *info, t_sem *semaphores)
{
	int				philo_num;
	pid_t			pid;
	const long long	start_time = get_time();

	philo_num = 0;
	while (philo_num < info->head_cnt)
	{
		pid = fork();
		if (pid == CHILD)
		{
			info->philo_num = philo_num;
			info->t_start = start_time;
			start_routine(info, semaphores, philo_num);
			return ;
		}
		else if (pid == FAIL)
		{
			clear_semaphores(semaphores, info->sem_names, info->head_cnt);
			exit_program(info, semaphores, 1);
		}
		else
			info->pid[philo_num] = pid;
		philo_num++;
	}
}
