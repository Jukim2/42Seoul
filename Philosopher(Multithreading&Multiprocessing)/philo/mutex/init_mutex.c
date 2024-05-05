/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy_mutex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:23:29 by jukim2            #+#    #+#             */
/*   Updated: 2023/07/04 18:55:30 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	make_fork_mutex(t_info *info, int idx)
{
	if (pthread_mutex_init(&(info->fork[idx]), 0) == -1)
	{
		destroy_mutex(info, idx);
		return (0);
	}
	else
		return (1);
}

int	make_meal_mutex(t_info *info, int idx)
{
	if (pthread_mutex_init(&(info->meal_mutex[idx]), 0) == -1)
	{
		destroy_mutex_failed_by_meal(info, idx);
		return (0);
	}
	else
		return (1);
}

int	make_end_mutex(t_info *info, int idx)
{
	if (pthread_mutex_init(&(info->end_mutex[idx]), 0) == -1)
	{
		destroy_mutex_failed_by_end(info, idx);
		return (0);
	}
	else
		return (1);
}
