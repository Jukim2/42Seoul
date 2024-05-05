/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_semaphore_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:26:47 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 13:51:36 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>

#include <fcntl.h>

void	make_semaphores(t_info *info, t_sem *sems)
{
	memset(sems, 0, sizeof(t_sem));
	open_meal_update_sem(info, sems);
	sems->meal_finished_sem = sem_open("meal_finished_sem", \
			O_CREAT | O_EXCL, 0644, 0);
	sems->fork_sem = sem_open("fork_sem", O_CREAT | O_EXCL, 0644, 0);
	sems->end_sem = sem_open("end_sem", O_CREAT | O_EXCL, 0644, 0);
	sems->fork_auth_sem = sem_open("fork_auth_sem", \
			O_CREAT | O_EXCL, 0644, 0);
	sems->print_sem = sem_open("print_sem", O_CREAT | O_EXCL, 0644, 1);
	if (sems->meal_finished_sem == SEM_FAILED || sems->fork_sem == SEM_FAILED
		|| sems->end_sem == SEM_FAILED || sems->fork_auth_sem == SEM_FAILED
		|| sems->print_sem == SEM_FAILED)
	{
		clear_unfailed_sem(info, sems);
		exit_program(info, NULL, 1);
	}
}

void	open_meal_update_sem(t_info *info, t_sem *sems)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	sems->meal_update_sem = malloc(sizeof(sem_t *) * info->head_cnt);
	if (!sems->meal_update_sem)
		exit_program(info, NULL, 1);
	while (i < info->head_cnt)
	{
		sems->meal_update_sem[i] = sem_open(info->sem_names[i], \
			O_CREAT | O_EXCL, 0644, 0);
		if (sems->meal_update_sem[i] == 0)
		{
			while (j < i)
			{
				close_unlink_semaphore(sems->meal_update_sem[j], \
					info->sem_names[j]);
				j++;
			}
			exit_program(info, sems, 1);
		}
		i++;
	}
}

void	clear_unfailed_sem(t_info *info, t_sem *semaphores)
{
	int	i;

	i = 0;
	while (i < info->head_cnt)
	{
		close_unlink_semaphore(semaphores->meal_update_sem[i], \
			info->sem_names[i]);
		i++;
	}
	if (semaphores->meal_finished_sem != SEM_FAILED)
		close_unlink_semaphore(semaphores->meal_finished_sem, \
			"meal_finished_sem");
	if (semaphores->fork_sem != SEM_FAILED)
		close_unlink_semaphore(semaphores->fork_sem, "fork_sem");
	if (semaphores->end_sem != SEM_FAILED)
		close_unlink_semaphore(semaphores->end_sem, "end_sem");
	if (semaphores->fork_auth_sem != SEM_FAILED)
		close_unlink_semaphore(semaphores->fork_auth_sem, "fork_auth_sem");
	if (semaphores->print_sem != SEM_FAILED)
		close_unlink_semaphore(semaphores->print_sem, "print_sem");
}

void	increase_semaphores(t_info *info, t_sem *semaphores)
{
	int	i;

	i = 0;
	while (i < info->head_cnt)
	{
		sem_post(semaphores->meal_update_sem[i]);
		sem_post(semaphores->fork_sem);
		if (i % 2 == 1)
		{
			sem_post(semaphores->fork_auth_sem);
		}
		i++;
	}
	if (info->head_cnt == 1)
		sem_post(semaphores->fork_auth_sem);
}
