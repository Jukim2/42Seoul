/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:01:55 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/20 16:39:23 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
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
		free (info);
		return (NULL);
	}
	info->sem_names = malloc(sizeof(char *) * info->head_cnt);
	if (!info->sem_names || !make_sem_names(info->sem_names, info->head_cnt))
	{
		free (info);
		return (NULL);
	}
	info->pid = malloc(sizeof(pid_t) * (info->head_cnt + 1));
	if (!info->pid)
	{
		free (info->sem_names);
		free (info);
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

int	make_sem_names(char **sem_names, int head_cnt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < head_cnt)
	{
		sem_names[i] = ft_strfjoin("philo", ft_itoa(i));
		if (!sem_names)
		{
			while (j < i)
				free (sem_names[j++]);
			free (sem_names);
			return (0);
		}
		i++;
	}
	return (1);
}
