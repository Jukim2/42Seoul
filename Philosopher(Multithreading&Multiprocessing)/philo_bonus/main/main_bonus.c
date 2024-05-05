/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:02:17 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 13:23:32 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_info		*info;
	t_sem		semaphores;

	if (argc < 5)
	{
		printf("Error : Need more argument\n");
		return (0);
	}
	info = set_info(argc, argv);
	if (!info)
		return (0);
	unlink_semaphores(info->sem_names, info->head_cnt);
	make_semaphores(info, &semaphores);
	make_philosophers(info, &semaphores);
	make_monitor(info, &semaphores);
	increase_semaphores(info, &semaphores);
	sem_wait(semaphores.end_sem);
	clear_semaphores(&semaphores, info->sem_names, info->head_cnt);
	exit_program(info, &semaphores, 0);
}

void	kill_all_process(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->head_cnt + 1 && info->pid[i] != 0)
	{		
		kill(info->pid[i++], SIGKILL);
	}
}

void	exit_program(t_info *info, t_sem *semaphores, int exit_value)
{
	kill_all_process(info);
	if (semaphores)
		free(semaphores->meal_update_sem);
	free_info(info);
	exit(exit_value);
}

void	free_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->head_cnt)
		free (info->sem_names[i++]);
	free(info->sem_names);
	free(info->pid);
	free(info);
}
