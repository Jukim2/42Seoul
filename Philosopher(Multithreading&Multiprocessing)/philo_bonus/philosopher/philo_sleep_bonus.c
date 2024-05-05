/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:35:46 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 11:29:46 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	philo_sleep(t_info *info, t_sem *semaphores)
{
	const long long	action_time = get_time();

	print_msg(info, semaphores, "is sleeping");
	count_time(info, info->t_sleep, action_time);
}
