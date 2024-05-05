/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:45:02 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/22 11:29:54 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	philo_think(t_info *info, t_sem *semaphores)
{
	print_msg(info, semaphores, "is thinking");
	usleep(100);
}
