/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_semaphore_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:03:38 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/20 15:24:38 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	unlink_semaphores(char **sem_names, int head_cnt)
{
	int	i;

	i = 0;
	while (i < head_cnt)
	{
		sem_unlink(sem_names[i++]);
	}
	sem_unlink("end_sem");
	sem_unlink("start_sem");
	sem_unlink("meal_finished_sem");
	sem_unlink("fork_sem");
	sem_unlink("fork_auth_sem");
	sem_unlink("print_sem");
}

void	clear_semaphores(t_sem *semaphores, char **sem_names, int head_cnt)
{
	int	i;

	i = 0;
	while (i < head_cnt)
	{
		close_unlink_semaphore(semaphores->meal_update_sem[i], sem_names[i]);
		i++;
	}
	close_unlink_semaphore(semaphores->fork_sem, "fork_sem");
	close_unlink_semaphore(semaphores->end_sem, "end_sem");
	close_unlink_semaphore(semaphores->fork_auth_sem, "fork_auth_sem");
	close_unlink_semaphore(semaphores->print_sem, "print_sem");
	close_unlink_semaphore(semaphores->meal_finished_sem, "meal_finished_sem");
}

void	close_unlink_semaphore(sem_t *semaphore, char *name)
{
	sem_close(semaphore);
	sem_unlink(name);
}
