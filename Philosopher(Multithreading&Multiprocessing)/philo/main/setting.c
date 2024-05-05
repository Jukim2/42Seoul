/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:01:55 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/20 13:53:39 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdlib.h>
#include <string.h>

t_info	*set_info(int argc, char *argv[])
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	memset(info, 0, sizeof(t_info));
	if (!set_program_argument(info, argc, argv))
	{
		free_info(info);
		return (NULL);
	}
	if (!allocate_space(info))
	{
		free_info(info);
		return (NULL);
	}
	if (!initiate_mutex(info))
	{
		free_info(info);
		return (NULL);
	}
	return (info);
}

int	set_program_argument(t_info *info, int argc, char *argv[])
{
	info->head_cnt = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->min_dine = ft_atoi(argv[5]);
	if (info->head_cnt <= 0 || info->t_die < 0 || info->t_eat < 0
		|| info->t_sleep < 0 || info->min_dine < 0)
		return (0);
	else
		return (1);
}

int	allocate_space(t_info *info)
{
	info->t_last_meal = malloc(sizeof(long long) * info->head_cnt);
	memset(info->t_last_meal, 0, sizeof(long long) * info->head_cnt);
	info->meal_taken = malloc(sizeof(long long) * info->head_cnt);
	memset(info->meal_taken, 0, sizeof(long long) * info->head_cnt);
	info->is_end = malloc(sizeof(long long) * info->head_cnt);
	memset(info->is_end, 0, sizeof(long long) * info->head_cnt);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->head_cnt);
	info->meal_mutex = malloc(sizeof(pthread_mutex_t) * info->head_cnt);
	info->end_mutex = malloc(sizeof(pthread_mutex_t) * info->head_cnt);
	if (!info->t_last_meal || !info->meal_taken || !info->is_end
		|| !info->fork || !info->meal_mutex ||!info->end_mutex)
		return (0);
	else
		return (1);
}

int	initiate_mutex(t_info *info)
{
	int	idx;

	idx = 0;
	if (pthread_mutex_init(&(info->print_mutex), 0) == -1)
		return (0);
	else if (pthread_mutex_init(&(info->ready_mutex), 0) == -1)
	{
		pthread_mutex_destroy(&(info->print_mutex));
		return (0);
	}
	while (idx < info->head_cnt)
	{
		if (!make_fork_mutex(info, idx) || !make_meal_mutex(info, idx)
			|| !make_end_mutex(info, idx))
			return (0);
		idx++;
	}
	return (1);
}
