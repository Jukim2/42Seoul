/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_one_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:55:06 by jukim2            #+#    #+#             */
/*   Updated: 2023/07/04 18:54:20 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	is_one_fork(t_phil *philo, int right_fork, int left_fork)
{
	while (right_fork == left_fork)
	{
		if (i_am_dead(philo))
		{
			pthread_mutex_unlock(&(philo->info->fork[right_fork]));
			pthread_mutex_unlock(&(philo->info->print_mutex));
			return (1);
		}
	}
	return (0);
}
