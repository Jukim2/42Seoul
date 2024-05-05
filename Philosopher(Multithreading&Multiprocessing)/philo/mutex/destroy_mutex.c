/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:20:46 by kjs               #+#    #+#             */
/*   Updated: 2023/07/09 13:03:31 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	destroy_mutex(t_info *info, int idx)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(info->print_mutex));
	pthread_mutex_destroy(&(info->ready_mutex));
	pthread_mutex_destroy(&(info->err_mutex));
	while (i < idx)
	{
		pthread_mutex_destroy(&(info->fork[i]));
		pthread_mutex_destroy(&(info->meal_mutex[i]));
		pthread_mutex_destroy(&(info->end_mutex[i++]));
	}
}

void	destroy_mutex_failed_by_meal(t_info *info, int idx)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(info->print_mutex));
	pthread_mutex_destroy(&(info->ready_mutex));
	pthread_mutex_destroy(&(info->err_mutex));
	while (i < idx - 1)
	{
		pthread_mutex_destroy(&(info->fork[i]));
		pthread_mutex_destroy(&(info->meal_mutex[i]));
		pthread_mutex_destroy(&(info->end_mutex[i++]));
	}
	pthread_mutex_destroy(&(info->fork[i]));
}

void	destroy_mutex_failed_by_end(t_info *info, int idx)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(info->print_mutex));
	pthread_mutex_destroy(&(info->ready_mutex));
	pthread_mutex_destroy(&(info->err_mutex));
	while (i < idx - 1)
	{
		pthread_mutex_destroy(&(info->fork[i]));
		pthread_mutex_destroy(&(info->meal_mutex[i]));
		pthread_mutex_destroy(&(info->end_mutex[i++]));
	}
	pthread_mutex_destroy(&(info->fork[i]));
	pthread_mutex_destroy(&(info->meal_mutex[i]));
}
